#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sfssd.sh,v 1.1 2003/03/25 15:51:51 grant Exp $
#
# start script for SFS server daemon 

# PROVIDE: sfssd
# REQUIRE: mountd

. /etc/rc.subr

name="sfssd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/etc/sfs/sfsrwsd_config"
extra_commands="keygen reload"

sfssd_keygen()
{
        (
        umask 022
        if [ -f @PREFIX@/etc/sfs/sfs_host_key ]; then
                echo "You already have a host key" \
                    "in @PREFIX@/etc/sfs/sfs_host_key"
        else
		@PREFIX@/bin/sfskey gen -P -K -l sfs_host_key \
		    @PREFIX@/etc/sfs/sfs_host_key
        fi
        )
}

sfssd_precmd()
{
	if [ ! -f @PREFIX@/etc/sfs/sfs_host_key ]; then
                run_rc_command keygen
        fi
}

keygen_cmd=sfssd_keygen
start_precmd=sfssd_precmd

load_rc_config $name
run_rc_command "$1"
