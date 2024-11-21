#!/bin/sh
#
# $NetBSD: netatalk.sh,v 1.1 2024/11/21 15:26:08 hauke Exp $
#

# PROVIDE: netatalk
# REQUIRE: NETWORKING mountcritremote syslogd

$_rc_subr_loaded . /etc/rc.subr

name="netatalk"
rcvar=$name
command="/usr/pkg/libexec/netatalk/${name}"
pidfile="/var/spool/lock/${name}"
required_files="/etc/${name}/afp.conf /etc/${name}/extmap.conf"

load_rc_config $name
run_rc_command "$1"
