#!@SH@
#
# $NetBSD: deluser.sh,v 1.3 2006/01/06 00:15:21 joerg Exp $
#
# This is a deluser script for NetBSD systems whose userdel(8) doesn't
# accept "$" in the username.

awkprog="@AWK@"
mktempprog="@MKTEMP@"
pwdmkdbprog="@PWD_MKDB@"
rmprog="@RM@"

progname=deluser

usage() {
	echo "Usage: $progname [-n] name"
	exit 1
}

doit=""

while getopts n flag; do
	case $flag in
	n)	doit=":" ;;
	esac
done
shift `expr $OPTIND - 1`

if [ $# -lt 1 ]; then
	usage
fi

name="$1"

case "$name" in
*:*)
	echo "$progname: \`$name' is not a valid user name" 1>&2
	exit 1
esac

ptmp=`$mktempprog -q /etc/ptmp`
case "$ptmp" in
/etc/ptmp)
	;;
*)
	echo "$progname: can't create /etc/ptmp" 1>&2
	exit 1
	;;
esac

if [ ! -f /etc/master.passwd ]; then
	echo "$progname: /etc/master.passwd not found" 1>&2
	$rmprog -f $ptmp
	exit 1
fi

$awkprog -v name="${name}" '						\
	BEGIN { FS = ":" }						\
	{								\
		if ($1 != name)						\
			print $0;					\
	}' /etc/master.passwd > $ptmp

$doit $pwdmkdbprog -p $ptmp
rc=$?

$rmprog -f $ptmp
exit $rc
