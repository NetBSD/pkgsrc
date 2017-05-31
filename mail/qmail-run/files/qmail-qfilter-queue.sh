#!@SH@
#
# Wrapper for qmail-queue that filters messages before injecting
#   into the queue.
#
# Using this wrapper, executable filters:
# * Must be placed in @PKG_SYSCONFDIR@/filters
# * Must have filenames matching "ofmipd-*" or "smtpd-*"
# * Will be executed with no arguments
# * Will be executed in sort(1) order

CAT=@CAT@
ECHO=@ECHO@
PKG_SYSCONFDIR=@PKG_SYSCONFDIR@
PREFIX=@PREFIX@
SED=@SED@
SORT=@SORT@

warn() {
	${ECHO} >&2 "$@"
}

choose_glob() {
	local _progname _glob
	_progname="$1"
	case "${_progname}" in
	qmail-qfilter-ofmipd-queue)	_glob='ofmipd-*'	;;
	qmail-qfilter-smtpd-queue)	_glob='smtpd-*'		;;
	qmail-qfilter-queue)		_glob='qfilter-*'	;;
	esac
	${ECHO} "${_glob}"
}

choose_filters() {
	local _glob _filters _possible_filters _filter
	_glob="$1"
	_possible_filters=$(${ECHO} ${PKG_SYSCONFDIR}/filters/${_glob} | ${SORT})
	if [ "${_possible_filters}" = "${PKG_SYSCONFDIR}/filters/${_glob}" ]; then
		_filters="${CAT}"
	else
		for _filter in ${_possible_filters}; do
			[ -x "${_filter}" ] && _filters="${_filters} ${_filter}"
		done
		[ -z "${_filters}" ] && _filters="${CAT}"
	fi
	${ECHO} "${_filters}"
}

qfilter_args() {
	local _filters
	_filters="$1"
	${ECHO} ${_filters} | ${SED} -e 's| | -- |g'
}

main() {
	local _progname _glob _filters _args _cmd
	_progname=$(basename "$0")
	_glob=$(choose_glob "${_progname}")
	_filters=$(choose_filters "${_glob}")
	_args=$(qfilter_args "${_filters}")
	_cmd="${PREFIX}/bin/qmail-qfilter ${_args}"
	exec ${_cmd}
}

main "$@"
