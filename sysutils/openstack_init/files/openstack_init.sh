#!/bin/sh

# PROVIDE: openstack_init
# REQUIRE: mountcritlocal
# BEFORE: SERVERS

$_rc_subr_loaded . /etc/rc.subr

name="openstack_init"
start_cmd="openstack_init"

openstack_init()
{
	test "x`hostname`" = "x" && eval $( /usr/pkg/sbin/openstack_init.py )
}

load_rc_config $name
run_rc_command "$1"

