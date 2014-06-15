#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smmsp.sh,v 1.3 2014/06/15 20:48:49 jnemeth Exp $
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
pidfile="@VARBASE@/spool/clientmqueue/sm-client.pid"
required_files="/etc/mail/submit.cf"
extra_commands="reload"

smbin="@PREFIX@/libexec/sendmail/sendmail"
smmsp_flags="-Lsm-msp-queue -Ac -q30m"
command=$smbin

load_rc_config $name
run_rc_command "$1"
