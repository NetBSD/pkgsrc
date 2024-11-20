#!/bin/sh
#
# $NetBSD: mdnsd.sh,v 1.1 2024/11/20 17:56:20 hauke Exp $
#

# PROVIDE: mdnsd
# REQUIRE: network mountcritlocal staticroute
# BEFORE:  NETWORKING

if [ -f /etc/rc.subr ]
then
    $_rc_subr_loaded . /etc/rc.subr
fi

name="mdnsd"
rcvar=$name
command="@PREFIX@/sbin/$name"
pidfile="@VARBASE@/run/mdnsd/${name}.pid"
start_precmd="mdnsd_precmd"

mdnsd_precmd()
{
    if [ ! -d @VARBASE@/run/mdnsd ]; then
        mkdir -p -m 755 @VARBASE@/run/mdnsd
    fi
    chown @MDNS_USER@:@MDNS_GROUP@ @VARBASE@/run/mdnsd
}
                                                        
load_rc_config $name
run_rc_command "$1"
