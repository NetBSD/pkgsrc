#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smtpfront.sh,v 1.1.1.1 2005/07/20 03:30:19 schmonz Exp $
#

# PROVIDE: smtpfront
# REQUIRE: qmailsend cvm

name="smtpfront"

# User-settable rc.conf variables and their default values:
: ${smtpfront_postenv:="CVM_LOOKUP_SECRET='' CVM_LOOKUP='cvm-local:@VARBASE@/run/cvm-qmail'"}
: ${smtpfront_tcpflags:="-vRl0"}
: ${smtpfront_tcphost:="0"}
: ${smtpfront_tcpport:="25"}
: ${smtpfront_datalimit:="2000000"}
: ${smtpfront_pretcpserver:=""}
: ${smtpfront_presmtpd:=""}
: ${smtpfront_postsmtpd:=""}
: ${smtpfront_log:="YES"}
: ${smtpfront_logcmd:="logger -t nb${name} -p mail.info"}
: ${smtpfront_nologcmd:="@LOCALBASE@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/control/concurrencyincoming"
required_files="${required_files} @PKG_SYSCONFDIR@/tcp.smtp.cdb"
required_files="${required_files} @PKG_SYSCONFDIR@/control/rcpthosts"
command="@LOCALBASE@/bin/tcpserver"
procname=${name}
start_precmd="smtpfront_precmd"
extra_commands="cdb"
cdb_cmd="smtpfront_cdb"

smtpfront_precmd()
{
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for SMTP
	# service. Use argv0(1) to set procname to "smtpfront".
	if [ -f /etc/rc.subr ]; then
		checkyesno smtpfront_log || smtpfront_logcmd=${smtpfront_nologcmd}
	fi
	command="@SETENV@ - ${smtpfront_postenv} @LOCALBASE@/bin/softlimit -m ${smtpfront_datalimit} ${smtpfront_pretcpserver} @LOCALBASE@/bin/argv0 @LOCALBASE@/bin/tcpserver ${name} ${smtpfront_tcpflags} -x @PKG_SYSCONFDIR@/tcp.smtp.cdb -c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencyincoming` -u `@ID@ -u qmaild ` -g `@ID@ -g qmaild` ${smtpfront_tcphost} ${smtpfront_tcpport} ${smtpfront_presmtpd} @LOCALBASE@/bin/smtpfront-qmail ${smtpfront_postsmtpd} 2>&1 | @LOCALBASE@/bin/setuidgid qmaill ${smtpfront_logcmd}"
	command_args="&"
	rc_flags=""
}

smtpfront_cdb()
{
	@ECHO@ "Reloading @PKG_SYSCONFDIR@/tcp.smtp."
	@LOCALBASE@/bin/tcprules @PKG_SYSCONFDIR@/tcp.smtp.cdb @PKG_SYSCONFDIR@/tcp.smtp.tmp < @PKG_SYSCONFDIR@/tcp.smtp
	@CHMOD@ 644 @PKG_SYSCONFDIR@/tcp.smtp.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	smtpfront_precmd
	eval ${command} ${smtpfront_flags} ${command_args}
fi
