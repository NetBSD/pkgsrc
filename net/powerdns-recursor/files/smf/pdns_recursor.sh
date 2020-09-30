#!@SMF_METHOD_SHELL@
#
# $NetBSD: pdns_recursor.sh,v 1.1 2020/09/30 11:53:07 otis Exp $
#

. /lib/svc/share/smf_include.sh

if [ ! -d @VARBASE@/run/pdns-recursor ]; then
	@MKDIR@ @VARBASE@/run/pdns-recursor
	@CHMOD@ 0755 @VARBASE@/run/pdns-recursor
fi

case "$1" in
   start)
      @PREFIX@/sbin/pdns_recursor --daemon
      ;;
   stop)
      @PREFIX@/bin/rec_control quit
      ;;
   refresh)
      $0 stop
      $0 start
      ;;
esac
