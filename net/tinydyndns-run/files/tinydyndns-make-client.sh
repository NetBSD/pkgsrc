#!@SH@
#
# $NetBSD: tinydyndns-make-client.sh,v 1.2 2020/10/19 07:15:55 schmonz Exp $
#
# @PKGNAME@ program to generate a dynamic DNS client.

if [ -z "$1" ]; then
	echo "Usage: $0 hostname" >&2
	exit 1
fi

dyn_hostname="$1"
DOMAIN=$(@HEAD@ -1 @PKG_SYSCONFDIR@/domain)

cat <<EOF
#!@SH@

dyn_hostname=${dyn_hostname}
dyn_password=your-password-here

TCPCLIENT=@PREFIX@/bin/tcpclient
DOMAIN=${DOMAIN}
PORT=110

main() {
	\${TCPCLIENT} \${DOMAIN} \${PORT} @SH@ -c "exec 0<&6; exec 1>&7
		echo USER \${dyn_hostname}
		read input
		echo PASS \${dyn_password}
		read input
		echo QUIT
		read input"
}

main "\$@"
exit \$?
EOF
