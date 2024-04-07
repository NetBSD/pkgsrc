#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dkimproxy_out.sh,v 1.1 2024/04/07 18:22:08 ryoon Exp $
#
# PROVIDE: dkimproxy_out
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dkimproxy_out"
rcvar=$name
command="@PREFIX@/bin/dkimproxy.out"
command_interpreter="@PERL5@"
pidfile="@VARBASE@/run/dkimproxy/${name}.pid"
command_args="--pidfile=${pidfile} --daemonize --conf_file=@PKG_SYSCONFDIR@/dkimproxy_out.conf --user=@DKIMPROXY_USER@ --group=@DKIMPROXY_GROUP@"
required_files="@PKG_SYSCONFDIR@/dkimproxy_out.conf"
start_precmd="dkimproxy_precmd"

dkimproxy_precmd()
{
	if [ ! -d @VARBASE@/run/dkimproxy ]; then
		@MKDIR@ @VARBASE@/run/dkimproxy
		@CHMOD@ 0750 @VARBASE@/run/dkimproxy
		@CHOWN@ @DKIMPROXY_USER@:@DKIMPROXY_GROUP@ @VARBASE@/run/dkimproxy
	fi

	if [ -f @VARBASE@/run/dkimproxy/${name}.sock ]; then
		@RM@ -f @VARBASE@/run/dkimproxy/${name}.sock
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${dkimproxy_flags} ${command_args}
fi
