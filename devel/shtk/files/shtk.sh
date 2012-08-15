#! @SHTK_SHELL@
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

# \file shtk.sh
# Entry point and main program logic.
#
# For simplicity reasons, we cannot rely on any of our own modules to
# implement this file.  Doing so, while possible, would complicate the
# creation of the final shtk script for no real advantage.

set -e


# Location of the shtk modules.
: ${SHTK_MODULESDIR:="@SHTK_MODULESDIR@"}


# Default shell to use when generating scripts.
: ${SHTK_SHELL:="@SHTK_SHELL@"}


# Version of the package.
SHTK_VERSION="@SHTK_VERSION@"


# Base name of the running script.
_ProgName="${0##*/}"


# Prints a runtime error and exits.
#
# \param ... The message to print.  Can be provided as multiple words and, in
#     that case, they are joined together by a single whitespace.
error() {
    echo "${_ProgName}: E: $*" 1>&2
    exit 1
}


# Prints an usage error and exits.
#
# \param ... The message to print.  Can be provided as multiple words and, in
#     that case, they are joined together by a single whitespace.
usage_error() {
    echo "${_ProgName}: E: $*" 1>&2
    echo "Type 'man ${_ProgName}' for help" 1>&2
    exit 1
}


# Command to build a script that uses shtk libraries.
#
# \params ... Options and arguments to the command.
shtk_build() {
    local main=main
    local output=
    local shell="${SHTK_SHELL}"

    while getopts ':m:o:s:' arg "${@}"; do
        case "${arg}" in
            m)  # Main function name.
                main="${OPTARG}"
                ;;

            o)  # Output file.
                output="${OPTARG}"
                ;;

            s)  # Shell to use.
                shell="${OPTARG}"
                ;;

            \?)
                usage_error "Unknown option -${OPTARG}"
                ;;
        esac
    done
    shift $((${OPTIND} - 1))

    [ ${#} -eq 1 ] || usage_error "build takes one argument only"

    local input="${1}"; shift
    case "${input}" in
        *.sh)
            [ -n "${output}" ] || output="$(echo ${input} | sed -e 's,\.sh$,,')"
            ;;

        *)
            [ -n "${output}" ] || usage_error "Input file should" \
                "end in .sh or you must specify -o"
            ;;
    esac

    [ "${input}" = - -o -e "${input}" ] || error "Cannot open ${input}"

    # Note that we use the built-in value of SHTK_MODULESDIR unconditionally
    # instead of what the environment says to avoid possible side-effects that
    # would be easy to debug.
    sed -e "s,__SHTK_MODULESDIR__,@SHTK_MODULESDIR@,g" \
        -e "s,__SHTK_SH__,${shell},g" \
        "${SHTK_MODULESDIR}/bootstrap.subr" \
        | grep -v '^#[^!].*' | grep -v '^#$' >"${output}.tmp"
    if [ "${input}" = - ]; then
        cat >>"${output}.tmp"
    else
        cat "${input}" >>"${output}.tmp"
    fi
    [ -z "${main}" ] || echo "${main} \"\${@}\"" >>"${output}.tmp"
    chmod +x "${output}.tmp"
    if ! mv "${output}.tmp" "${output}"; then
        rm -f "${output}.tmp"
        error "Failed to create ${output}"
    fi
}


# Gets version information about shtk.
shtk_version() {
    [ ${#} -eq 0 ] || usage_error "version does not take any arguments"

    echo "shtk ${SHTK_VERSION}"
}


# Entry point to the program.
#
# \param ... Command-line arguments to be processed.
#
# \return An exit code to be returned to the user.
shtk_main() {
    [ ${#} -ge 1 ] || usage_error "No command specified"

    local exit_code=0

    local command="${1}"; shift
    case "${command}" in
        build|version)
            "shtk_${command}" "${@}" || exit_code="${?}"
            ;;

        *)
            usage_error "Unknown command ${command}"
            ;;
    esac

    return "${exit_code}"
}


shtk_main "${@}"
