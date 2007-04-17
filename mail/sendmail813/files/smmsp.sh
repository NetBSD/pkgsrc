#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smmsp.sh,v 1.1.1.1 2007/04/17 10:16:53 jnemeth Exp $
#

# REQUIRE: mail

#	The only function of the smmsp process is to push locally
#	collected mail (which got stuck in the local client queue)
#	to a more fully functional smtp relay.  It is not a fully
#	functional smtp daemon.
#
#	It can, however, be used as a completely unprivileged
#	replacement for hosts that were previously using a "null
#	client" configuration and a smart relay.

. /etc/rc.subr

name="smmsp"
rcvar=$name
command="/usr/sbin/sendmail"
pidfile="@VARBASE@/spool/clientmqueue/sm-client.pid"
required_files="/etc/mail/submit.cf"
smbin="@PREFIX@/libexec/sendmail/sendmail"
smmsp_flags="-Lsm-msp-queue -Ac -q30m"

load_rc_config $name
run_rc_command "$1"
