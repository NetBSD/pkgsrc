#! /bin/sh
#
# $NetBSD: munin-node.sh,v 1.1.1.1 2006/06/04 20:53:57 he Exp $
#
# PROVIDE: munin-node
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start munin-node:
#
# munin_node=YES
#

if [ -f /etc/rc.subr ]
then
    . /etc/rc.subr
fi

name="munin_node"
rcvar=$name
command=@PREFIX@/sbin/munin-node
command_interpreter=@PERL@
required_files=@PKG_SYSCONFDIR@/munin/munin-node.conf

if [ ! -d @STATEDIR@ ]; then
	mkdir @STATEDIR@
	chown munin:munin /var/run/munin
fi

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	exec ${command} ${command_args}
fi
