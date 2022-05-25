#!@CD_SCRIPTS_SHELL@
#
# $NetBSD: srs-milter-in.sh,v 1.1 2022/05/25 15:45:32 manu Exp $
#
# PROVIDE: srs_milter_in
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="srs_milter_in"
rcvar=$name
command="@PREFIX@/sbin/srs-milter"
pidfile="@VARBASE@/run/srs-milter/${name}.pid"
keyfile="/etc/mail/srs.key"
command_args="-P ${pidfile} -s local:@VARBASE@/run/srs-milter/${name}.sock" 
command_args="${command_args} --srs-secret-file=${keyfile}"
command_args="${command_args} --user @MILTER_USER@ --reverse"
required_files="${keyfile}"
start_precmd="srs_milter_precmd"

srs_milter_precmd()
{
	if [ ! -f ${keyfile} ]; then
		( umask 077; dd if=/dev/random bs=256 count=1 of=${keyfile} )
		chown srs ${keyfile}
	fi

        if [ ! -d @VARBASE@/run/srs-milter ]; then
                mkdir -p @VARBASE@/run/srs-milter
                chown srs @VARBASE@/run/srs-milter
                chmod 0750 @VARBASE@/run/srs-milter
        fi

	if [ -e @VARBASE@/run/srs-milter/${name}.sock ]; then
		rm -f @VARBASE@/run/srs-milter/${name}.sock
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${srs_milter_flags} ${command_args}
fi
