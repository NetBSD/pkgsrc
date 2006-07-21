#! /bin/sh
#
# $NetBSD: munin-node.sh,v 1.3 2006/07/21 23:28:37 abs Exp $
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
required_files=@PKG_SYSCONFDIR@/munin-node.conf

if [ ! -d @STATEDIR@ ]; then
	mkdir @STATEDIR@
	chown @MUNIN_USER@:@MUNIN_GROUP@ @STATEDIR@
fi
if [ ! -d @MUNIN_RUN@ ]; then
	mkdir @MUNIN_RUN@
	chown @MUNIN_USER@:@MUNIN_GROUP@ @MUNIN_RUN@
fi

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	exec ${command} ${command_args}
fi
