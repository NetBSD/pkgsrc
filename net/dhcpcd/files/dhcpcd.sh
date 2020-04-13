#!@RCD_SCRIPTS_SHELL@

# PROVIDE: dhcpcd
# REQUIRE: network mountcritlocal
# BEFORE:  NETWORKING
# KEYWORD: chrootdir

# To get syslog support for chroots, add this to rc.conf:
#dhcpcd_chrootdir=/var/chroot/dhcpcd
# The directory should match the home directory of the dhcpcd user.

$_rc_subr_loaded . /etc/rc.subr

name="dhcpcd"
rcvar=$name
command="@PREFIX@/sbin/${name}"

load_rc_config $name

# Work out what pidfile dhcpcd will use based on flags
if [ -n "$flags" ]; then
	myflags=$flags
else
	eval myflags=\$${name}_flags
fi
pidfile=$(eval $command -P $myflags 2>/dev/null)
: ${pidfile:=/var/run/$name.pid}
unset myflags

run_rc_command "$1"
