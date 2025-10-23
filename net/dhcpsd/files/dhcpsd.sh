#!@RCD_SCRIPTS_SHELL@

# PROVIDE: dhcpsd
# REQUIRE: NETWORKING
# KEYWORD: chrootdir

# To get syslog support for chroots, add this to rc.conf:
#dhcpsd_chrootdir=/var/chroot/dhcpsd
# The directory should match the home directory of the dhcpsd user.

$_rc_subr_loaded . /etc/rc.subr

name="dhcpsd"
rcvar=$name
command="@PREFIX@/sbin/$name"

load_rc_config $name
run_rc_command "$1"
