#!@RCD_SCRIPTS_SHELL@

# PROVIDE: svnserve
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="svnserve"
rcvar=${name}
command="/usr/pkg/bin/${name}"
svnserve_user="svn"
pidfile="/var/run/${name}.pid"

start_precmd="${name}_prestart"

svnserve_prestart()
{
    rc_flags="-d --pid-file=${pidfile} ${rc_flags}"
}

load_rc_config $name
run_rc_command "$1"
