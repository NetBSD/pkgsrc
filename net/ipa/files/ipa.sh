#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ipa.sh,v 1.1 2003/05/30 11:53:17 salo Exp $
#

# PROVIDE: ipa
# REQUIRE: ipfilter

. /etc/rc.subr

name="ipa"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"
required_dir="/var/${name}"
stop_cmd="ipa_stop"
reconfigure_cmd="ipa_reconfigure"
dump_cmd="ipa_dump"
extra_commands="reconfigure dump"

ipa_stop()
{
	echo "Stopping ${name}."

	${command} -k shutdown
}

ipa_reconfigure()
{
	echo "Reloading ${name} configuration."

	${command} -k reconfigure
}

ipa_dump()
{
	echo "Dumping ${name} stats."

	${command} -k dump
}

load_rc_config $name
run_rc_command "$1"
