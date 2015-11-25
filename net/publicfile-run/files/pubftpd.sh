#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pubftpd.sh,v 1.2 2015/11/25 12:52:12 jperkin Exp $
#
# @PKGNAME@ script to control publicfile ftpd (FTP server)
#

# PROVIDE: pubftpd
# REQUIRE: NETWORKING mountcritremote syslogd
# BEFORE:  DAEMON

name="pubftpd"

# User-settable rc.conf variables and their default values:
: ${pubftpd_root:="@VARBASE@/public"}
: ${pubftpd_postenv:=""}
: ${pubftpd_datalimit:="50000"}
: ${pubftpd_localname:="0"}
: ${pubftpd_backlog:="20"}
: ${pubftpd_conlimit:="40"}
: ${pubftpd_host:="0"}
: ${pubftpd_port:="21"}
: ${pubftpd_log:="YES"}
: ${pubftpd_logcmd:="logger -t nb${name} -p ftp.info"}
: ${pubftpd_nologcmd:="@PREFIX@/bin/multilog -*"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_dirs="${pubftpd_root}"
command="@PREFIX@/libexec/pubftpd"
procname=${name}
start_precmd="pubftpd_precmd"

pubftpd_precmd()
{
	if [ -f /etc/rc.subr ]; then
		checkyesno pubftpd_log || pubftpd_logcmd=${pubftpd_nologcmd}
	fi
 	command="@SETENV@ - ${pubftpd_postenv} @PREFIX@/bin/envuidgid pubftp @PREFIX@/bin/softlimit -o20 -d${pubftpd_datalimit} @PREFIX@/libexec/pubftpd -vDRH -l${pubftpd_localname} -b${pubftpd_backlog} -c${pubftpd_conlimit} ${pubftpd_host} ${pubftpd_port} @PREFIX@/publicfile/bin/ftpd ${pubftpd_root} 2>&1 | @PREFIX@/bin/setuidgid publog ${pubftpd_logcmd}"
	command_args="&"
	rc_flags=""
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	pubftpd_precmd
	eval ${command} ${pubftpd_flags} ${command_args}
fi
