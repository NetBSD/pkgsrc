#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mldonkey.sh,v 1.3 2004/12/25 19:13:34 jmmv Exp $
#
# KEYWORD: shutdown
# PROVIDE: mldonkey
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="mldonkey"
rcvar=${name}
command="@PREFIX@/libexec/mldonkey/mlnet"
command_args=">@MLDONKEY_HOME@/log 2>&1 &"
required_dirs="@MLDONKEY_HOME@"
mldonkey_chdir="@MLDONKEY_HOME@"
mldonkey_group="@MLDONKEY_GROUP@"
mldonkey_user="@MLDONKEY_USER@"
start_cmd="mldonkey_start"

mldonkey_start() {
	if [ -f /etc/rc.subr ]; then
		@ECHO@ "Starting mldonkey."
	else
		@ECHO@ " ${name}"
	fi
	@SU@ -l ${mldonkey_user} \
	     -c "${command} ${mldonkey_flags} ${command_args}" &
}

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "${1}"
else
	mldonkey_start
fi
