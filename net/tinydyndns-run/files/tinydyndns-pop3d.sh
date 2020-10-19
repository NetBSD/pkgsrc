#!@SH@
#
# $NetBSD: tinydyndns-pop3d.sh,v 1.2 2020/10/19 07:15:55 schmonz Exp $
#
# @PKGNAME@ fake POP3 server.

main() {
	echo '+OK '
	read input
	if [ "$input" = 'LIST' ]; then
		echo '+OK'
		echo '.'
	elif [ "$input" = 'STAT' ]; then
		echo '+OK 0 0'
	fi
	read input
	echo '+OK'
	return 0
}

main "$@"
exit $?
