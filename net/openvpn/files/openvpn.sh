#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openvpn.sh,v 1.4 2011/08/03 08:33:33 cheusov Exp $
#
# PROVIDE: openvpn
# REQUIRE: NETWORKING
#
# To start openvpn at startup, copy this script to /etc/rc.d.  You will
# also need to set the following variables:
#
# openvpn=YES
#
# The following variables are optional:
#
#	openvpn_cfg="server.conf"	# whitespace-separated list of
#					# OpenVPN config files relative to
#					# directory @PKG_SYSCONFDIR@.  If
#					# set, then an openvpn process is
#					# started for each file, otherwise
#					# a process is started for all
#					# *.conf files.
#
#       openvpn_chrootdir="dir"         # Chroot to "dir" after initialization.
#                                       # See --chroot option for details.
#
#       openvpn_flags="flags"           # Flags to pass to the openvpn(8) command
#
# The "reset" action will trigger a SIGUSR1 restart of the OpenVPN
# process.  Please read the openvpn(8) man page for more details.
#
# For information on how to write an OpenVPN config file, please read the
# openvpn(8) man page or check the website at:
#
#	http://openvpn.net/
#

. /etc/rc.subr

name="openvpn"
rcvar=$name
sysconfdir="@PKG_SYSCONFDIR@"
command="@PREFIX@/sbin/openvpn"
command_args="--cd $sysconfdir --daemon"
extra_commands="reload reset"
required_dirs="$sysconfdir"

start_cmd="openvpn_start"
reset_cmd="openvpn_reset"

openvpn_start()
{
	command_args="$command_args $openvpn_flags"
	if test -n "$openvpn_chrootdir"; then
		command_args="$command_args --chroot $openvpn_chrootdir"
	fi

	: ${openvpn_cfg="*.conf"}

	for d in $required_dirs; do
		if [ ! -d "$d/." ]; then
			warn "$d is not a directory."
			return 1
		fi
	done
	if [ -z "$openvpn_cfg" ]; then
		warn "\$openvpn_cfg is empty."
		return 1
	fi
	savewd="$PWD"
	cd $sysconfdir
	for f in $openvpn_cfg; do
		if [ ! -r "$f" ]; then
			warn "$f is not readable."
			cd $savewd
			return 1
		fi
	done
	echo "Starting ${name}."
	for f in $openvpn_cfg; do
		doit="$command $command_args --config $f"
		if ! eval $doit; then
			cd $savewd
			return 1
		fi
	done
	cd $savewd
}

openvpn_reset()
{
	if [ -z "$rc_pid" ]; then
		if [ -n "$pidfile" ]; then
			echo 1>&2 \
		    "${name} not running? (check $pidfile)."
		else
			echo 1>&2 "${name} not running?"
		fi
		exit 1
	fi
	echo "Triggering SIGUSR1 restart of ${name}."
	if ! eval $_precmd && [ -z "$rc_force" ]; then
		return 1
	fi
	_doit="kill -${sig_reload:-USR1} $rc_pid"
	if [ -n "$_user" ]; then
		_doit="su -m $_user -c 'sh -c \"$_doit\"'"
	fi
	if ! eval $_doit && [ -z "$rc_force" ]; then
		return 1
	fi
}

load_rc_config $name
run_rc_command "$1"
