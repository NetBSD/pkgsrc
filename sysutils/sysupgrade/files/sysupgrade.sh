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
    config_set AUTOCLEAN "yes"
    config_set CACHEDIR "${SYSUPGRADE_CACHEDIR}"
    config_set ETCUPDATE "yes"
    config_set KERNEL "AUTO"
    config_set SETS "AUTO"
}


# Interprets magic configuration values.
#
# This function should be called after the configuration file has been loaded.
# It takes care of performing any required post-processing on the configuration
# variables, such as expanding the magic AUTO keyword to the actual value.
sysupgrade_auto_config() {
    if [ "$(config_get_default KERNEL "")" = "AUTO" ]; then
        local kernel="$(config_get_default DESTDIR "")/netbsd"
        if [ -e "${kernel}" ]; then
            local kernel_name="$(config -x "${kernel}" | head -n 1 \
                                 | cut -d \" -f 2)"
            [ -n "${kernel_name}" ] || utils_error "Failed to determine" \
                "kernel name; please set KERNEL explicitly"
            config_set KERNEL "${kernel_name}"
        else
            config_unset KERNEL
        fi
    fi

    if [ "$(config_get_default SETS "")" = "AUTO" ]; then
        local mtree="$(config_get_default DESTDIR "")/etc/mtree/"
        if [ -d "${mtree}" ]; then
            local all_sets="$(cd "${mtree}" && echo set.* \
                              | sed -e 's,set\.,,g')"
            config_set SETS "${all_sets}"
        else
            config_unset SETS
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
                utils_usage_error "Unknown option -${OPTARG}"
                ;;
        esac
    done
    shift $((${OPTIND} - 1))

    [ ${#} -eq 0 ] || utils_usage_error "config does not take any arguments"

    [ "${eval_auto}" = no ] || sysupgrade_auto_config

    for var in ${SYSUPGRADE_CONFIG_VARS}; do
        if config_has "${var}"; then
            echo "${var} = $(config_get "${var}")"
        else
            echo "${var} is undefined"
        fi
    done
}


# Gets the path to a set, and ensures it exists.
#
# \post The path to the tgz of the set is printed on stdout.
#
# \param set_name The name of the set to query.
get_set() {
    local set_name="${1}"; shift

    echo "$(config_get CACHEDIR)/${set_name}.tgz"
}


# Ensures that a given set exists.
#
# \param set_name The name of the set to query.
require_set() {
    local set_name="${1}"; shift

    local set_tgz="$(get_set "${set_name}")"
    [ -f "${set_tgz}" ] || utils_error "Cannot find ${set_name}; did you run" \
        "'${Utils_ProgName} fetch' first?"
}


# Extracts a set into the destdir.
#
# The set to be extracted must have been previously fetched into the cache
# directory by sysupgrade_fetch command.
#
# \param set_name Name of the set to extract, without the .tgz extension.
extract_set() {
    local set_name="${1}"; shift

    require_set "${set_name}"

    local destdir="$(config_get_default DESTDIR "")"
    local set_tgz="$(get_set "${set_name}")"

    utils_info "Extracting ${set_name} into ${destdir}/"
    [ -z "${destdir}" ] || utils_run mkdir -p "${destdir}"
    progress -zf "${set_tgz}" tar -xp -C "${destdir}/" -f -
}


# Fetches the release sets into the cache directory.
#
# \param releasedir Optional override of the release directory to use.
sysupgrade_fetch() {
    [ ${#} -lt 2 ] \
        || utils_usage_error "fetch takes zero or one arguments"

    [ -z "${1}" ] || config_set "RELEASEDIR" "${1}"

    local releasedir="$(config_get RELEASEDIR)"
    local cachedir="$(config_get CACHEDIR)"
    local fetch_sets="$(config_get SETS)"
    if config_has KERNEL; then
        fetch_sets="${fetch_sets} kern-$(config_get KERNEL)"
    fi

    case "${releasedir}" in
        ftp://*|http://*)
            mkdir -p "${cachedir}"

            for set_name in ${fetch_sets}; do
                local file="${cachedir}/${set_name}.tgz"
                if [ -f "${file}" ]; then
                    utils_warning "Reusing existing ${file}"
                else
                    local url="${releasedir}/binary/sets/${set_name}.tgz"
                    utils_info "Downloading ${url} into ${cachedir}"
                    rm -f "${file}"
                    ftp -R -o"${file}.tmp" "${url}" \
                        || utils_error "Failed to fetch ${url}"
                    mv "${file}.tmp" "${file}"
                fi
            done
            ;;

        /*)
            mkdir -p "${cachedir}"

            for set_name in ${fetch_sets}; do
                local src="${releasedir}/binary/sets/${set_name}.tgz"
                utils_info "Linking local ${src} into ${cachedir}"
                [ -f "${src}" ] || utils_error "Cannot open ${src}"
                ln -s -f "${src}" "${cachedir}/${set_name}.tgz" \
                    || utils_error "Failed to link ${src} into ${cachedir}"
            done
            ;;

        *)
            utils_error "Don't know how to fetch from ${releasedir}; must" \
                "be an absolute path or an FTP/HTTP site"
            ;;
    esac
}


# Installs a new kernel from a set.
#
# \param kernel_name Name of the kernel set to use; optional.
sysupgrade_kernel() {
    [ ${#} -lt 2 ] \
        || utils_usage_error "kernel takes zero or one arguments"

    local kernel_name
    if [ -n "${1}" ]; then
        kernel_name="${1}"
    elif config_has KERNEL; then
        kernel_name="$(config_get KERNEL)"
    else
        utils_info "Skipping kernel installation (KERNEL not set)"
        return 0
    fi

    require_set "kern-${kernel_name}"

    local destdir="$(config_get_default DESTDIR "")"
    utils_info "Upgrading kernel using ${kernel_name} in ${destdir}/"

    if [ -f "${destdir}/netbsd" ]; then
        utils_info "Backing up 'netbsd' kernel as 'onetbsd'"
        cp "${destdir}/netbsd" "${destdir}/onetbsd"
    fi
    extract_set "kern-${kernel_name}"
}


# Installs new kernel modules.
sysupgrade_modules() {
    [ ${#} -eq 0 ] \
        || utils_usage_error "modules does not take any arguments"

    if ! utils_contains modules $(config_get SETS); then
        utils_info "Skipping modules installation (modules not in SETS)"
        return 0
    fi

    utils_info "Upgrading kernel modules"

    extract_set modules
}


# Installs new sets.
#
# \param ... Names of the sets to extract, to override SETS.
sysupgrade_sets() {
    utils_info "Upgrading base system"

    local sets=
    for set_name in "${@:-$(config_get SETS)}"; do
        case "${set_name}" in
            *etc) ;;  # Handled by etcupdate.
            kern-*) ;;  # Handled by kernel.
            modules) ;;  # Handled by modules.
            *) sets="${sets} ${set_name}" ;;
        esac
    done

    for set_name in ${sets}; do
        require_set "${set_name}"
    done

    for set_name in ${sets}; do
        extract_set "${set_name}"
    done
}


# Runs etcupdate to install new configuration files.
sysupgrade_etcupdate() {
    [ ${#} -eq 0 ] || utils_usage_error "etcupdate does not take any arguments"

    if config_has DESTDIR; then
        utils_info "Skipping etcupdate (DESTDIR upgrades not supported)"
        return 0
    fi

    local sets="$(utils_filter '*etc' $(config_get SETS))"
    if [ -z "${sets}" ]; then
        utils_info "Skipping etcupdate (no etc sets in SETS)"
        return 0
    fi
    if ! utils_contains etc ${sets}; then
        utils_info "Skipping etcupdate (required etc not in SETS)"
        return 0
    fi

    local sflags=
    for set_name in ${sets}; do
        require_set "${set_name}"
        sflags="${sflags} -s$(get_set "${set_name}")"
    done

    utils_info "Upgrading /etc interactively"
    etcupdate -a -l ${sflags}
}


# Runs postinstall to validate the updated system.
#
# \param ... Arguments to pass to postinstall(8).
sysupgrade_postinstall() {
    local sets=
    local sets="$(utils_filter '*etc' $(config_get SETS))"
    if [ -z "${sets}" ]; then
        utils_info "Skipping postinstall (no etc sets in SETS)"
        return 0
    fi
    if ! utils_contains etc ${sets}; then
        utils_info "Skipping postinstall (required etc not in SETS)"
        return 0
    fi

    local sflags=
    for set_name in ${sets}; do
        require_set "${set_name}"
        sflags="${sflags} -s$(get_set "${set_name}")"
    done

    utils_info "Performing postinstall checks"
    local destdir="$(config_get_default DESTDIR "")"
    if config_has POSTINSTALL_AUTOFIX; then
        postinstall "-d${destdir}/" ${sflags} fix \
            $(config_get POSTINSTALL_AUTOFIX)
    fi
    postinstall "-d${destdir}/" ${sflags} "${@:-check}" \
        || utils_error "Some postinstall(8) checks have failed"
}


# Cleans up the cache directory.
sysupgrade_clean() {
    [ ${#} -eq 0 ] || utils_usage_error "clean does not take any arguments"

    utils_info "Cleaning downloaded files"
    rm -f "$(config_get CACHEDIR)"/*.tgz*
}


# Automated upgrade procedure.
#
# This is just a convenience mechanism to execute all the different steps of the
# upgrade.
#
# \param releasedir Optional override of the release directory to use.
sysupgrade_auto() {
    [ ${#} -lt 2 ] \
        || utils_usage_error "auto takes zero or one arguments"

    [ -z "${1}" ] || config_set "RELEASEDIR" "${1}"

    local stages=
    stages="fetch modules kernel sets"
    config_get_bool "ETCUPDATE" && stages="${stages} etcupdate"
    stages="${stages} postinstall"
    config_get_bool "AUTOCLEAN" && stages="${stages} clean"

    utils_info "Starting auto-update with stages: ${stages}"
    for stage in ${stages}; do
        sysupgrade_${stage}
    done

    config_get_bool "AUTOCLEAN" || utils_info "Distribution sets not deleted;" \
        "further ${Utils_ProgName} commands will reuse them"
}


# Entry point to the program.
#
# \param ... Command-line arguments to be processed.
#
# \return An exit code to be returned to the user.
sysupgrade_main() {
    local config_file="${SYSUPGRADE_ETCDIR}/sysupgrade.conf"

    config_init ${SYSUPGRADE_CONFIG_VARS}

    while getopts ':c:d:o:' arg "${@}"; do
        case "${arg}" in
            c)  # Path to the configuration file.
                config_file="${OPTARG}"
                ;;

            d)  # Path to the destdir.
                config_set DESTDIR "${OPTARG}"
                ;;

            o)  # Override for a particular configuration variable.
                config_override "${OPTARG}"
                ;;

            \?)
                utils_usage_error "Unknown option -${OPTARG}"
                ;;
        esac
    done
    shift $((${OPTIND} - 1))

    [ ${#} -ge 1 ] || utils_usage_error "No command specified"

    local exit_code=0

    local command="${1}"; shift
    case "${command}" in
        auto|clean|etcupdate|fetch|kernel|modules|sets|postinstall)
            sysupgrade_set_defaults
            config_load "${config_file}"
            sysupgrade_auto_config
            "sysupgrade_$(echo "${command}" | tr - _)" "${@}" \
                || exit_code="${?}"
            ;;

        config)
            sysupgrade_set_defaults
            config_load "${config_file}"
            "sysupgrade_$(echo "${command}" | tr - _)" "${@}" \
                || exit_code="${?}"
            ;;

        *)
            utils_usage_error "Unknown command ${command}"
            ;;
    esac

    return "${exit_code}"
}
