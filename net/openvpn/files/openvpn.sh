#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openvpn.sh,v 1.1 2005/08/17 19:55:57 jlam Exp $
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
extra_commands="reload"
required_dirs="$sysconfdir"

start_cmd="openvpn_start"

openvpn_start()
{
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
	for f in $openvpn_cfg; do
		doit="$command $command_args --config $f"
		if ! eval $doit; then
			cd $savewd
			return 1
		fi
	done
	cd $savewd
}

load_rc_config $name
run_rc_command "$1"
