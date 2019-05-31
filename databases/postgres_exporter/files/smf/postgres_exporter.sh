#!@SMF_METHOD_SHELL@
#
# $NetBSD: postgres_exporter.sh,v 1.1 2019/05/31 14:42:04 jperkin Exp $
#
# Init script for postgres_exporter.  This is non-standard, but required so
# that we can source a configuration file and pass environment variables that
# include the database password to the program.
#
# As we need to use it anyway, we use it for everything, rather than splitting
# configuration between the config file and SMF variables.
#

. /lib/svc/share/smf_include.sh

. @PKG_SYSCONFDIR@/env.conf

case "$1" in
start)
	@LOCALBASE@/bin/postgres_exporter
	;;
*)
	echo "Usage: $0 start" >&2
	exit 1
	;;
esac

exit ${SMF_EXIT_OK}
