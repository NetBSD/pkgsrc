#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cfexecd.sh,v 1.1 2004/08/19 17:13:36 ben Exp $
#
# start script for cfexecd

# PROVIDE: cfexecd
# REQUIRE: network

. /etc/rc.subr

name="cfexecd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="/var/cfengine/inputs/update.conf"
extra_commands="keygen reload"

cfexecd_keygen()
{
        (
        umask 022
        if [ -f /var/cfengine/ppkeys/localhost.priv ]; then
                echo "You already have a host key" \
                    "in /var/cfengine/ppkeys/localhost.priv"
        else
                @PREFIX@/sbin/cfkey
        fi
        )
}

cfexecd_precmd()
{
        if [ ! -f /var/cfengine/ppkeys/localhost.priv ]; then
                run_rc_command keygen
        fi
}

keygen_cmd=cfexecd_keygen
start_precmd=cfexecd_precmd

load_rc_config $name
run_rc_command "$1"
