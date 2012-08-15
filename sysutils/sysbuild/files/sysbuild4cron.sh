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

# \file sysbuild4cron.sh
# Entry point and main program logic.

shtk_import cli


# Paths to installed files.
#
# Can be overriden for test purposes only.
: ${SYSBUILD_BINDIR="@SYSBUILD_BINDIR@"}


# Sends an email notification upon a failure.
#
# \param logfile File containing the output of the failed command.
# \param recipient Who to send the email to.
# \param ... Command that failed.
sysbuild4cron_email() {
    local logfile="${1}"; shift
    local recipient="${1}"; shift

    local maxlines=100
    {
        echo "The following command has failed:"
        echo
        echo "    $*"
        echo
        echo "The output of the failed command has been left in:"
        echo
        echo "    ${logfile}"
        echo
        echo "The last ${maxlines} of the log follow:"
        echo
        tail -n${maxlines} "${logfile}"
    } | mail -s "sysbuild failure report" "${recipient}"
}


# Entry point to the program.
#
# \param ... Command-line arguments to be processed.
#
# \return An exit code to be returned to the user.
sysbuild4cron_main() {
    local logdir="${HOME}/sysbuild/log"
    local recipient="$(id -u -n)"

    while getopts ':l:r:' arg "${@}"; do
        case "${arg}" in
            l)  # Location of logs.
                case "${OPTARG}" in
                    /*) logdir="${OPTARG}" ;;
                    *) logdir="$(pwd)/${OPTARG}" ;;
                esac
                ;;

            r)  # Email recipient.
                recipient="${OPTARG}"
                ;;

            \?)
                shtk_cli_usage_error "Unknown option -${OPTARG}"
                ;;
        esac
    done
    shift $((${OPTIND} - 1))

    set -- "${SYSBUILD_BINDIR}/sysbuild" "${@}"

    if [ ! -d "${logdir}" ]; then
        mkdir -p "$(dirname "${logdir}")" >/dev/null 2>/dev/null || true
        mkdir "${logdir}" \
            || shtk_cli_error "Failed to create directory '${logdir}'"
    fi

    local exit_code=0
    local logfile="${logdir}/$(shtk_cli_progname).$(date +%Y%m%d%H%M%S).log"
    "${@}" >"${logfile}" 2>&1 \
        || sysbuild4cron_email "${logfile}" "${recipient}" "${@}"
}
