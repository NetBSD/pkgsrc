#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dkim-filter.sh,v 1.1 2008/02/19 13:23:06 adrianp Exp $
#
# PROVIDE: dkimfilter
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dkimfilter"
rcvar=$name
command="@PREFIX@/bin/dkim-filter"
pidfile="@VARBASE@/run/dkim-filter/${name}.pid"
command_args="-P ${pidfile} -l -p @VARBASE@/run/dkim-filter/${name}.sock -x @PKG_SYSCONFDIR@/dkim-filter.conf -u @DKIM_USER@:@DKIM_GROUP@"
required_files="@PKG_SYSCONFDIR@/dkim-filter.conf"
start_precmd="dkimfilter_precmd"

dkimfilter_precmd()
{
	if [ ! -d @VARBASE@/run/dkim-filter ]; then
		@MKDIR@ @VARBASE@/run/dkim-filter
		@CHMOD@ 0750 @VARBASE@/run/dkim-filter
		@CHOWN@ @DKIM_USER@:@DKIM_GROUP@ @VARBASE@/run/dkim-filter
	fi

	if [ -f @VARBASE@/run/dkim-filter/${name}.sock ]; then
		@RM@ -f @VARBASE@/run/dkim-filter/${name}.sock
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${dkimfilter_flags} ${command_args}
fi
