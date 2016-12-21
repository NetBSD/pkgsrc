#!/bin/sh
#
# $NetBSD: amavisd-milter.sh,v 1.1 2016/12/21 12:05:51 kivinen Exp $
#

# PROVIDE: amavisd-milter
# REQUIRE: amavisd
# BEFORE:  mail

$_rc_subr_loaded . /etc/rc.subr

name="amavisd_milter"
rcvar=$name
command="/usr/pkg/sbin/amavisd-milter"
amavisd_milter_user="vscan"
amavisd_milter_group="vscan"

load_rc_config $name
run_rc_command "$1"

# EOF
