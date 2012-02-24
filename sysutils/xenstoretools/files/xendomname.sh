#!@RCD_SCRIPTS_SHELL@

# PROVIDE: xendomname
# REQUIRE: network mountcritlocal
# BEFORE:  dhcpcd
#
# Sets the hostname to the xen domain name
# (dhcpcd can pick it up and send it to the DHCP server.)
#

$_rc_subr_loaded . /etc/rc.subr

name=xendomname
rcvar=$name
start_cmd="xendomname_start"

xendomname_start()
{
	mount /kern || true
	dname="`@PREFIX@/bin/xenstore-read name`"
	echo "Setting hostname to xen domain name: $dname"
	hostname "$dname"
}

load_rc_config $name
run_rc_command "$1"
