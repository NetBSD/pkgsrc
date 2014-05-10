#!/bin/sh

# PROVIDE: xen_network
# REQUIRE: xenguest network

$_rc_subr_loaded . /etc/rc.subr

name="xen_network"
start_cmd="network_start"

network_start()
{
	eval $( @PREFIX@/sbin/xen_network.py )
}

load_rc_config $name
run_rc_command "$1"

