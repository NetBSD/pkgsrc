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

# \file sysbuild.sh
# Entry point and main program logic.

shtk_import cli
shtk_import config
shtk_import cvs
shtk_import process


# List of valid configuration variables.
#
# Please remember to update sysbuild(1) if you change this list.
SYSBUILD_CONFIG_VARS="BUILD_ROOT BUILD_TARGETS CVSROOT CVSTAG INCREMENTAL_BUILD
                      MACHINES NJOBS RELEASEDIR SRCDIR UPDATE_SOURCES XSRCDIR"


# Paths to installed files.
#
# Can be overriden for test purposes only.
: ${SYSBUILD_ETCDIR="@SYSBUILD_ETCDIR@"}


# Sets defaults for configuration variables that need a value.
#
# This function should be before the configuration file has been loaded.  This
# means that the user can undefine a required configuration variable, but we let
# him shoot himself in the foot if he so desires.
sysbuild_set_defaults() {
    # Please remember to update sysbuild(1) if you change any default values.
    shtk_config_set BUILD_ROOT "${HOME}/sysbuild"
    shtk_config_set BUILD_TARGETS "release"
    shtk_config_set CVSROOT ":ext:anoncvs@anoncvs.NetBSD.org:/cvsroot"
    shtk_config_set INCREMENTAL_BUILD "false"
    shtk_config_set MACHINES "$(uname -m)"
    shtk_config_set RELEASEDIR "${HOME}/sysbuild/release"
    shtk_config_set SRCDIR "${HOME}/sysbuild/src"
    shtk_config_set UPDATE_SOURCES "true"
}


# Performs a build for a single machine type.
#
# \param machine The type of the machine to build for.
do_one_build() {
    local machine="${1}"; shift

    local basedir="$(shtk_config_get BUILD_ROOT)/${machine}"

    local jflag=
    if shtk_config_has NJOBS; then
        jflag="-j$(shtk_config_get NJOBS)"
    fi

    local uflag=
    if shtk_config_get_bool INCREMENTAL_BUILD; then
        uflag=-u

        # Get rid of any possibly-old modules; they are a constant source of
        # update-build problems.
        rm -rf "${basedir}/destdir/stand"/*
    else
        shtk_cli_info "Cleaning up previous build files"
        rm -rf "${basedir}/destdir"
        rm -rf "${basedir}/obj"
        rm -rf "${basedir}/tools"
    fi

    local xflag=
    local Xflag=
    if shtk_config_has XSRCDIR; then
        xflag=-x
        Xflag="-X$(shtk_config_get XSRCDIR)"
    fi

    ( cd "$(shtk_config_get SRCDIR)" && shtk_process_run ./build.sh \
        -D"${basedir}/destdir" \
        -M"${basedir}/obj" \
        -N2 \
        -R"$(shtk_config_get RELEASEDIR)" \
        -T"${basedir}/tools" \
        -U \
        ${Xflag} \
        ${jflag} \
        -m"${machine}" \
        ${uflag} \
        ${xflag} \
        $(shtk_config_get BUILD_TARGETS) )
}


# Builds the system.
#
# \params ... The options and arguments to the command.
sysbuild_build() {
    while getopts ':f' arg "${@}"; do
        case "${arg}" in
            f)  # Convenience flag for a "fast mode".
                shtk_config_set "INCREMENTAL_BUILD" "true"
                shtk_config_set "UPDATE_SOURCES" "false"
                ;;

            \?)
                shtk_cli_usage_error "Unknown option -${OPTARG}"
                ;;
        esac
    done
    shift $((${OPTIND} - 1))

    [ ${#} -eq 0 ] || shtk_config_set BUILD_TARGETS "${*}"

    if shtk_config_get_bool UPDATE_SOURCES; then
        sysbuild_fetch
    fi

    for machine in $(shtk_config_get MACHINES); do
        do_one_build "${machine}"
    done
}


# Dumps the loaded configuration.
#
# \params ... The options and arguments to the command.
sysbuild_config() {
    [ ${#} -eq 0 ] || shtk_cli_usage_error "config does not take any arguments"

    for var in ${SYSBUILD_CONFIG_VARS}; do
        if shtk_config_has "${var}"; then
            echo "${var} = $(shtk_config_get "${var}")"
        else
            echo "${var} is undefined"
        fi
    done
}


# Fetches a copy of the source tree, or updates an existing one.
#
# \params ... The options and arguments to the command.
sysbuild_fetch() {
    [ ${#} -eq 0 ] || shtk_cli_usage_error "fetch does not take any arguments"

    local cvsroot="$(shtk_config_get CVSROOT)"

    shtk_cli_info "Updating base source tree"
    shtk_cvs_fetch "${cvsroot}" src "$(shtk_config_get_default CVSTAG '')" \
        "$(shtk_config_get SRCDIR)"

    if shtk_config_has XSRCDIR; then
        shtk_cli_info "Updating X11 source tree"
        shtk_cvs_fetch "${cvsroot}" xsrc \
	    "$(shtk_config_get_default CVSTAG '')" "$(shtk_config_get XSRCDIR)"
    fi
}


# Loads the configuration file specified in the command line.
#
# \param config_name Name of the desired configuration.  It can be either a
#     configuration name (no slashes) or a path.
sysbuild_config_load() {
    local config_name="${1}"; shift

    local config_file=
    case "${config_name}" in
        */*|*.conf)
            config_file="${config_name}"
            ;;

        *)
            local candidates=
            candidates="${candidates} ${HOME}/.sysbuild/${config_name}.conf"
            candidates="${candidates} ${SYSBUILD_ETCDIR}/${config_name}.conf"
            for candidate in ${candidates}; do
                if [ -e "${candidate}" ]; then
                    config_file="${candidate}"
                    break
                fi
            done
            [ -n "${config_file}" ] \
                || shtk_cli_usage_error "Cannot locate configuration named" \
                "'${config_name}'"
            ;;
    esac
    shtk_config_load "${config_file}"
}


# Entry point to the program.
#
# \param ... Command-line arguments to be processed.
#
# \return An exit code to be returned to the user.
sysbuild_main() {
    local config_name="default"

    shtk_config_init ${SYSBUILD_CONFIG_VARS}

    while getopts ':c:o:' arg "${@}"; do
        case "${arg}" in
            c)  # Name of the configuration to load.
                config_name="${OPTARG}"
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
        build|config|fetch)
            sysbuild_set_defaults
            sysbuild_config_load "${config_name}"
            "sysbuild_${command}" "${@}" || exit_code="${?}"
            ;;

        *)
            shtk_cli_usage_error "Unknown command ${command}"
            ;;
    esac

    return "${exit_code}"
}
