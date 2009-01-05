#!@RCD_SCRIPTS_SHELL@

# PROVIDE:
# REQUIRE: LOGIN
# KEYWORD:

$_rc_subr_loaded . /etc/rc.subr

name="op_panel"
rcvar=$name
command="@PREFIX@/libexec/op_server.pl"
command_interpreter="@PERL5@"
pidfile="/var/run/$name.pid"
required_files="@PKG_SYSCONFDIR@/op_server.cfg"
extra_commands="reload"

command_args="-d -c @PKG_SYSCONFDIR@"

load_rc_config $name
run_rc_command "$1"
