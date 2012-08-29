#!@RCD_SCRIPTS_SHELL@

# PROVIDE: microcode
# REQUIRE: mountall
#
# attempts microcode update on all CPU cores (for Intel x86)
#

$_rc_subr_loaded . /etc/rc.subr

name=microcode
rcvar=$name
start_cmd="microcode_start"

_microcode_baremetal()
{
	ncpu=`/sbin/sysctl -n hw.ncpu`

	for i in `/usr/bin/jot - 0 \`expr $ncpu - 1\` 1`; do
		/usr/sbin/cpuctl ucode $i || true
	done
}

_microcode_xen()
{
	/usr/sbin/cpuctl ucode || true
}

microcode_start()
{
	if [ -e /kern/xen/privcmd ]; then
		_microcode_xen
	else
		_microcode_baremetal
	fi
}

load_rc_config $name
run_rc_command "$1"
