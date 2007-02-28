#!@SH@
#
# Wrapper for qmail-smtpd command chain that runs the first command
#   only if RELAYCLIENT is set, running the remaining commands
#   regardless. End the first command with "--".
#
# Useful for e.g. setting RBLSMTPD="" to avoid RBL-blocking an
#   authenticated user.

relayclient_isset()
{
	@SETENV@ | @GREP@ -q '^RELAYCLIENT=' >/dev/null 2>&1
}

main()
{
	local cmd1 arg
	cmd1=""
	while [ $# -gt 0 ]; do
		arg="$1"; shift
		if [ "${arg}" = '--' ]; then
			break
		else
			cmd1="${cmd1} ${arg}"
		fi
	done
	if [ $# -eq 0 ]; then
		@ECHO@ >&2 "usage: $0 command args -- command args"
		exit 111
	fi
	if relayclient_isset; then
		exec ${cmd1} "$@"
	else
		exec "$@"
	fi
}

main "$@"
exit $?
