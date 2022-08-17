#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: vaultwarden.sh,v 1.1 2022/08/17 15:44:16 hauke Exp $
#
# PROVIDE: vaultwarden
# REQUIRE: DAEMON
# KEYWORD: shutdown

name="vaultwarden"

command="@PREFIX@/sbin/daemonize"

pidfile="/var/run/${name}/${name}.pid"

task="@PREFIX@/sbin/${name}"
procname="${task}"

command_args="-p ${pidfile} \
    -u @VAULTWARDEN_USER@ \
    -c @VAULTWARDEN_DATADIR@ \
    -e @VAULTWARDEN_LOGDIR@/daemonize.stderr \
    -o @VAULTWARDEN_LOGDIR@/daemonize.stdout \
    -E ENV_FILE=@PKG_SYSCONFDIR@/${name}.env ${task}"

vaultwarden_precmd()
{
        if [ ! -e "@VARBASE@/run/${name}" ] ; then
                install -d -o @VAULTWARDEN_USER@ -g @VAULTWARDEN_GROUP@ \
		    @VARBASE@/run/${name};
        fi
}

if [ -f @SYSCONFBASE@/rc.subr ]; then
    	. @SYSCONFBASE@/rc.subr

	rcvar=${name}
	required_files="@PKG_SYSCONFDIR@/${name}.env"
	pidfile="@VARBASE@/run/${name}/${name}.pid"

	start_precmd="vaultwarden_precmd"

	load_rc_config ${name}
	run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
	vaultwarden_precmd
	${command} ${command_args}
fi
