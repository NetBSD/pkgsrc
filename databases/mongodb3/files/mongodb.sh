#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mongodb.sh,v 1.1 2019/06/30 13:48:06 gdt Exp $
#
# PROVIDE: mongodb
# REQUIRE: DAEMON LOGIN mountall
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start MongoDB:
#
# mongodb=YES
#
# The following variables are optional:
#
#     mongodb_user="@MONGODB_USER@"	# user to run mongod as
#     mongodb_group="@MONGODB_GROUP@"	# group to run mongod as
#     mongodb_dbpath="@MONGODB_DBPATH@"	# path to MongoDB database directory
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="mongodb"
rcvar=${name}
command="@PREFIX@/bin/mongod"
: ${mongodb_user:=@MONGODB_USER@}
: ${mongodb_group:=@MONGODB_GROUP@}
: ${mongodb_dbpath:=@MONGODB_DBPATH@}
pidfile="${mongodb_dbpath}/mongod.pid"
logfile="${mongodb_dbpath}/mongod.log"
required_dirs="${mongodb_dbpath}"

command_args="--fork --logpath ${logfile} --logappend --pidfilepath ${pidfile} --dbpath ${mongodb_dbpath} --smallfiles"

load_rc_config ${name}
run_rc_command "$1"
