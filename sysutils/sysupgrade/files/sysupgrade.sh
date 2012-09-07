# Copyright 2012 Google Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.
# * Neither the name of Google Inc. nor the names of its contributors
#   may be used to endorse or promote products derived from this software
#   without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# \file sysupgrade.sh
# Entry point and main program logic.

shtk_import cli
shtk_import config
shtk_import list
shtk_import process


# List of valid configuration variables.
#
# Please remember to update sysbuild(1) if you change this list.
SYSUPGRADE_CONFIG_VARS="AUTOCLEAN CACHEDIR DESTDIR ETCUPDATE KERNEL
                        POSTINSTALL_AUTOFIX RELEASEDIR SETS"


# Directory in which to keep downloaded release files.
#
# Can be overriden for test purposes only.
: ${SYSUPGRADE_CACHEDIR:="@SYSUPGRADE_CACHEDIR@"}


# Paths to installed files.
#
# Can be overriden for test purposes only.
: ${SYSUPGRADE_ETCDIR:="@SYSUPGRADE_ETCDIR@"}


# Sets defaults for configuration variables that need a value.
#
# This function should be called before the configuration file has been loaded.
# This means that the user can undefine a required configuration variable, but
# we let him shoot himself in the foot if he so desires.
sysupgrade_set_defaults() {
    # Please remember to update sysupgrade(8) if you change any default values.
    shtk_config_set AUTOCLEAN "yes"
    shtk_config_set CACHEDIR "${SYSUPGRADE_CACHEDIR}"
    shtk_config_set ETCUPDATE "yes"
    shtk_config_set KERNEL "AUTO"
    shtk_config_set SETS "AUTO"
}


# Interprets magic configuration values.
#
# This function should be called after the configuration file has been loaded.
# It takes care of performing any required post-processing on the configuration
# variables, such as expanding the magic AUTO keyword to the actual value.
sysupgrade_auto_config() {
    if [ "$(shtk_config_get_default KERNEL "")" = "AUTO" ]; then
        local kernel="$(shtk_config_get_default DESTDIR "")/netbsd"
        if [ -e "${kernel}" ]; then
            local kernel_path="$(config -x "${kernel}" | head -n 1 \
                                 | cut -d \" -f 2)"
            local kernel_name="${kernel_path##*/}"
            [ -n "${kernel_name}" ] || shtk_cli_error "Failed to determine" \
                "kernel name; please set KERNEL explicitly"
            shtk_config_set KERNEL "${kernel_name}"
        else
            shtk_config_unset KERNEL
        fi
    fi

    if [ "$(shtk_config_get_default SETS "")" = "AUTO" ]; then
        local mtree="$(shtk_config_get_default DESTDIR "")/etc/mtree/"
        if [ -d "${mtree}" ]; then
            local all_sets="$(cd "${mtree}" && echo set.* \
                              | sed -e 's,set\.,,g')"
            shtk_config_set SETS "${all_sets}"
        else
            shtk_config_unset SETS
        fi
    fi
}


# Dumps the loaded configuration.
#
# \params ... The options and arguments to the command.
sysupgrade_config() {
    local eval_auto=no
    while getopts ':a' arg "${@}"; do
        case "${arg}" in
            a)  # Evaluate automatic settings.
                eval_auto=yes
                ;;

            \?)
                shtk_cli_usage_error "Unknown option -${OPTARG}"
                ;;
        esac
    done
    shift $((${OPTIND} - 1))

    [ ${#} -eq 0 ] || shtk_cli_usage_error "config does not take any arguments"

    [ "${eval_auto}" = no ] || sysupgrade_auto_config

    for var in ${SYSUPGRADE_CONFIG_VARS}; do
        if shtk_config_has "${var}"; then
            echo "${var} = $(shtk_config_get "${var}")"
        else
            echo "${var} is undefined"
        fi
    done
}


# Gets the path to a file in the cache.
#
# \post The path to the file in the cache is printed on stdout.
#
# \param file The name of the file to query.
get_cached_file() {
    local file="${1}"; shift

    echo "$(shtk_config_get CACHEDIR)/${file}"
}


# Ensures that a given distribution file exists in the cache.
#
# \param file The name of the file to query.
require_cached_file() {
    local file="${1}"; shift

    local path="$(get_cached_file "${file}")"
    [ -f "${path}" ] || shtk_cli_error "Cannot find ${file}; did you run" \
        "'$(shtk_cli_progname) fetch' first?"
}


# Extracts a set into the destdir.
#
# The set to be extracted must have been previously fetched into the cache
# directory by sysupgrade_fetch command.
#
# \param set_name Name of the set to extract, without the .tgz extension.
extract_set() {
    local set_name="${1}"; shift

    require_cached_file "${set_name}.tgz"

    local destdir="$(shtk_config_get_default DESTDIR "")"
    local set_tgz="$(get_cached_file "${set_name}.tgz")"

    shtk_cli_info "Extracting ${set_name} into ${destdir}/"
    [ -z "${destdir}" ] || shtk_process_run mkdir -p "${destdir}"
    progress -zf "${set_tgz}" tar -xp -C "${destdir}/" -f -
}


# Fetches the release sets into the cache directory.
#
# \param releasedir Optional override of the release directory to use.
sysupgrade_fetch() {
    [ ${#} -lt 2 ] \
        || shtk_cli_usage_error "fetch takes zero or one arguments"

    [ -z "${1}" ] || shtk_config_set "RELEASEDIR" "${1}"

    local releasedir="$(shtk_config_get RELEASEDIR)"
    local cachedir="$(shtk_config_get CACHEDIR)"
    local fetch_files=
    for set_name in $(shtk_config_get SETS); do
        fetch_files="${fetch_files} binary/sets/${set_name}.tgz"
    done
    if shtk_config_has KERNEL; then
        local kernel_name="$(shtk_config_get KERNEL)"
        fetch_files="${fetch_files} binary/kernel/netbsd-${kernel_name}.gz"
    fi

    case "${releasedir}" in
        ftp://*|http://*)
            mkdir -p "${cachedir}"

            for relative_file in ${fetch_files}; do
                local local_file="${cachedir}/${relative_file##*/}"
                if [ -f "${local_file}" ]; then
                    shtk_cli_warning "Reusing existing ${local_file}"
                else
                    local url="${releasedir}/${relative_file}"
                    shtk_cli_info "Downloading ${url} into ${cachedir}"
                    rm -f "${local_file}"
                    local rflag=
                    [ ! -f "${local_file}.tmp" ] || rflag=-R
                    ftp ${rflag} -o"${local_file}.tmp" "${url}" \
                        || shtk_cli_error "Failed to fetch ${url}"
                    mv "${local_file}.tmp" "${local_file}"
                fi
            done
            ;;

        /*)
            mkdir -p "${cachedir}"

            for relative_file in ${fetch_files}; do
                local src="${releasedir}/${relative_file}"
                shtk_cli_info "Linking local ${src} into ${cachedir}"
                [ -f "${src}" ] || shtk_cli_error "Cannot open ${src}"
                ln -s -f "${src}" "${cachedir}/${relative_file##*/}" \
                    || shtk_cli_error "Failed to link ${src} into ${cachedir}"
            done
            ;;

        *)
            shtk_cli_error "Don't know how to fetch from ${releasedir}; must" \
                "be an absolute path or an FTP/HTTP site"
            ;;
    esac
}


# Installs a new kernel from a set.
#
# \param kernel_name Name of the kernel set to use; optional.
sysupgrade_kernel() {
    [ ${#} -lt 2 ] \
        || shtk_cli_usage_error "kernel takes zero or one arguments"

    local kernel_name
    if [ -n "${1}" ]; then
        kernel_name="${1}"
    elif shtk_config_has KERNEL; then
        kernel_name="$(shtk_config_get KERNEL)"
    else
        shtk_cli_info "Skipping kernel installation (KERNEL not set)"
        return 0
    fi

    require_cached_file "netbsd-${kernel_name}.gz"

    local destdir="$(shtk_config_get_default DESTDIR "")"
    shtk_cli_info "Upgrading kernel using ${kernel_name} in ${destdir}/"

    if gunzip -c "$(get_cached_file "netbsd-${kernel_name}.gz")" \
        >"${destdir}/nnetbsd"
    then
        if [ -f "${destdir}/netbsd" ]; then
            shtk_cli_info "Backing up 'netbsd' kernel as 'onetbsd'"
            ln -f "${destdir}/netbsd" "${destdir}/onetbsd"
        fi

        mv "${destdir}/nnetbsd" "${destdir}/netbsd"
    else
        rm -f "${destdir}/nnetbsd"
        shtk_cli_error "Failed to uncompress new kernel"
    fi
}


# Installs new kernel modules.
sysupgrade_modules() {
    [ ${#} -eq 0 ] \
        || shtk_cli_usage_error "modules does not take any arguments"

    if ! shtk_list_contains modules $(shtk_config_get SETS); then
        shtk_cli_info "Skipping modules installation (modules not in SETS)"
        return 0
    fi

    shtk_cli_info "Upgrading kernel modules"

    extract_set modules
}


# Installs new sets.
#
# \param ... Names of the sets to extract, to override SETS.
sysupgrade_sets() {
    local sets=
    for set_name in "${@:-$(shtk_config_get SETS)}"; do
        case "${set_name}" in
            *etc) ;;  # Handled by etcupdate.
            kern-*)
                shtk_cli_error "SETS should not contain any kernel sets;" \
                    "found ${set_name}"
                ;;
            modules) ;;  # Handled by modules.
            *) sets="${sets} ${set_name}" ;;
        esac
    done

    for set_name in ${sets}; do
        require_cached_file "${set_name}.tgz"
    done

    shtk_cli_info "Upgrading base system"
    for set_name in ${sets}; do
        extract_set "${set_name}"
    done
}


# Runs etcupdate to install new configuration files.
sysupgrade_etcupdate() {
    [ ${#} -eq 0 ] || shtk_cli_usage_error "etcupdate does not take any" \
        "arguments"

    if shtk_config_has DESTDIR; then
        shtk_cli_info "Skipping etcupdate (DESTDIR upgrades not supported)"
        return 0
    fi

    local sets="$(shtk_list_filter '*etc' $(shtk_config_get SETS))"
    if [ -z "${sets}" ]; then
        shtk_cli_info "Skipping etcupdate (no etc sets in SETS)"
        return 0
    fi
    if ! shtk_list_contains etc ${sets}; then
        shtk_cli_info "Skipping etcupdate (required etc not in SETS)"
        return 0
    fi

    local sflags=
    for set_name in ${sets}; do
        require_cached_file "${set_name}.tgz"
        sflags="${sflags} -s$(get_cached_file "${set_name}.tgz")"
    done

    shtk_cli_info "Upgrading /etc interactively"
    etcupdate -a -l ${sflags}
}


# Runs postinstall to validate the updated system.
#
# \param ... Arguments to pass to postinstall(8).
sysupgrade_postinstall() {
    local sets=
    local sets="$(shtk_list_filter '*etc' $(shtk_config_get SETS))"
    if [ -z "${sets}" ]; then
        shtk_cli_info "Skipping postinstall (no etc sets in SETS)"
        return 0
    fi
    if ! shtk_list_contains etc ${sets}; then
        shtk_cli_info "Skipping postinstall (required etc not in SETS)"
        return 0
    fi

    local sflags=
    for set_name in ${sets}; do
        require_cached_file "${set_name}.tgz"
        sflags="${sflags} -s$(get_cached_file "${set_name}.tgz")"
    done

    shtk_cli_info "Performing postinstall checks"
    local destdir="$(shtk_config_get_default DESTDIR "")"
    if shtk_config_has POSTINSTALL_AUTOFIX; then
        postinstall "-d${destdir}/" ${sflags} fix \
            $(shtk_config_get POSTINSTALL_AUTOFIX)
    fi
    postinstall "-d${destdir}/" ${sflags} "${@:-check}" \
        || shtk_cli_error "Some postinstall(8) checks have failed"
}


# Cleans up the cache directory.
sysupgrade_clean() {
    [ ${#} -eq 0 ] || shtk_cli_usage_error "clean does not take any arguments"

    shtk_cli_info "Cleaning downloaded files"
    rm -f "$(shtk_config_get CACHEDIR)"/*.*gz*
}


# Automated upgrade procedure.
#
# This is just a convenience mechanism to execute all the different steps of the
# upgrade.
#
# \param releasedir Optional override of the release directory to use.
sysupgrade_auto() {
    [ ${#} -lt 2 ] \
        || shtk_cli_usage_error "auto takes zero or one arguments"

    [ -z "${1}" ] || shtk_config_set "RELEASEDIR" "${1}"

    local stages=
    stages="fetch modules kernel sets"
    shtk_config_get_bool "ETCUPDATE" && stages="${stages} etcupdate"
    stages="${stages} postinstall"
    shtk_config_get_bool "AUTOCLEAN" && stages="${stages} clean"

    shtk_cli_info "Starting auto-update with stages: ${stages}"
    for stage in ${stages}; do
        sysupgrade_${stage}
    done

    shtk_config_get_bool "AUTOCLEAN" || shtk_cli_info "Distribution sets not" \
        "deleted; further $(shtk_cli_progname) commands will reuse them"
}


# Entry point to the program.
#
# \param ... Command-line arguments to be processed.
#
# \return An exit code to be returned to the user.
sysupgrade_main() {
    local config_file="${SYSUPGRADE_ETCDIR}/sysupgrade.conf"

    shtk_config_init ${SYSUPGRADE_CONFIG_VARS}

    while getopts ':c:d:o:' arg "${@}"; do
        case "${arg}" in
            c)  # Path to the configuration file.
                config_file="${OPTARG}"
                ;;

            d)  # Path to the destdir.
                shtk_config_set DESTDIR "${OPTARG}"
                ;;

            o)  # Override for a particular configuration variable.
                shtk_config_override "${OPTARG}"
                ;;

            \?)
                shtk_cli_usage_error "Unknown option -${OPTARG}"
                ;;
        esac
    done
    shift $((${OPTIND} - 1))

    [ ${#} -ge 1 ] || shtk_cli_usage_error "No command specified"

    local exit_code=0

    local command="${1}"; shift
    case "${command}" in
        auto|clean|etcupdate|fetch|kernel|modules|sets|postinstall)
            sysupgrade_set_defaults
            shtk_config_load "${config_file}"
            sysupgrade_auto_config
            "sysupgrade_$(echo "${command}" | tr - _)" "${@}" \
                || exit_code="${?}"
            ;;

        config)
            sysupgrade_set_defaults
            shtk_config_load "${config_file}"
            "sysupgrade_$(echo "${command}" | tr - _)" "${@}" \
                || exit_code="${?}"
            ;;

        *)
            shtk_cli_usage_error "Unknown command ${command}"
            ;;
    esac

    return "${exit_code}"
}
