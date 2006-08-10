#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mldonkey.sh,v 1.7 2006/08/10 11:35:26 jmmv Exp $
#
# KEYWORD: shutdown
# PROVIDE: mldonkey
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

: ${mldonkey_group=@MLDONKEY_GROUP@}
: ${mldonkey_home=@MLDONKEY_HOME@}
: ${mldonkey_logdir=@VARBASE@/log/mldonkey}
: ${mldonkey_rundir=@VARBASE@/run/mldonkey}
: ${mldonkey_user=@MLDONKEY_USER@}

name="mldonkey"
rcvar=${name}
command="@PREFIX@/libexec/mldonkey/mlnet"
command_args="-pid ${mldonkey_rundir} >${mldonkey_logdir}/mlnet.log 2>&1 &"
pidfile="${mldonkey_rundir}/mlnet.pid"
required_dirs="${mldonkey_home}"
start_cmd="mldonkey_start"

mldonkey_start() {
	if [ -f /etc/rc.subr ]; then
		@ECHO@ "Starting mldonkey."
	else
		@ECHO@ " ${name}"
	fi

	if [ ! -d ${mldonkey_logdir} ]; then
		mkdir -p ${mldonkey_logdir}
		chown ${mldonkey_user}:${mldonkey_group} ${mldonkey_logdir}
		chmod 0700 ${mldonkey_logdir}
	fi

	if [ ! -d ${mldonkey_rundir} ]; then
		mkdir -p ${mldonkey_rundir}
		chown ${mldonkey_user}:${mldonkey_group} ${mldonkey_rundir}
		chmod 0700 ${mldonkey_rundir}
	fi

	@SU@ -l ${mldonkey_user} -c \
		"HOME=${mldonkey_home} \
		 ${command} ${mldonkey_flags} ${command_args}"
}

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "${1}"
else
	mldonkey_start
fi
