#!@SH@
#
# $NetBSD: adduser.sh,v 1.3 2006/01/06 00:15:21 joerg Exp $
#
# This is an adduser script for NetBSD systems whose useradd(8) doesn't
# accept "$" in the username.  This script may be used for the
# "add machine script" in smb.conf.

awkprog="@AWK@"
catprog="@CAT@"
mktempprog="@MKTEMP@"
pwdmkdbprog="@PWD_MKDB@"
rmprog="@RM@"

progname=adduser

usage() {
	echo "Usage: $progname [-c comment] [-d homedir] [-n] [-r low..high]"
	echo "		[-s shell] -g gid name"
	exit 1
}

isnum() {
	case "$1" in
	0[0-9]*|*[!0-9]*)
		return 1
		;;
	esac
	return 0
}

doit=""
gid=""
minuid=1000
maxuid=60000
comment=""
homedir=""
shell=/sbin/nologin

while getopts c:d:g:nr:s: flag; do
	case $flag in
	c)	comment="${OPTARG}" ;;
	d)	homedir="${OPTARG}" ;;
	g)	gid="${OPTARG}" ;;
	n)	doit=":" ;;
	r)	minuid=${OPTARG%%..*}; maxuid=${OPTARG##*..} ;;
	s)	shell="${OPTARG}" ;;
	esac
done
shift `expr $OPTIND - 1`

if [ $# -lt 1 ]; then
	usage
fi

name="$1"
if [ -z "$gid" ]; then
	echo "$progname: \`-g gid' is a required option" 1>&2
	exit 1
fi
if ! isnum "$gid"; then
	echo "$progname: \`$gid' is not a valid gid" 1>&2
	exit 1
fi
if ! isnum "$minuid"; then
	echo "$progname: \`$minuid' is not a valid minimum uid" 1>&2
	exit 1
fi
if ! isnum "$maxuid"; then
	echo "$progname: \`$maxuid' is not a valid maximum uid" 1>&2
	exit 1
fi
if [ $minuid -gt $maxuid ]; then
	echo "$progname: \`$minuid..$maxuid' is not a valid range" 1>&2
	exit 1
fi
case "$comment" in
*:*)
	echo "$progname: \`$comment' is not a valid comment" 1>&2
	exit 1
	;;
esac
case "$homedir" in
*:*)
	echo "$progname: \`$homedir' is not a valid home directory" 1>&2
	exit 1
	;;
%*)
	# This is an unsubstituted variable (probably %H in smbd).
	# Silently change this to a proper default.
	#
	homedir="/nonexistent"
	;;
esac
case "$shell" in
*:*)
	echo "$progname: \`$shell' is not a valid shell" 1>&2
	exit 1
	;;
esac
case "$name" in
*:*)
	echo "$progname: \`$name' is not a valid username" 1>&2
	exit 1
	;;
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

$catprog /etc/master.passwd >> $ptmp

uid=`									\
	$awkprog -v minuid=$minuid -v maxuid=maxuid '			\
		BEGIN { FS = ":" }					\
		{ seen_uids[$3] = 1 }					\
		END {							\
			uid = minuid;					\
			while (uid <= maxuid) {				\
				if (uid in seen_uids) {			\
					uid++;				\
					continue;			\
				}					\
				print uid;				\
				exit;					\
			}						\
			print -1;					\
		}' $ptmp						\
`
if [ $uid -lt 0 ]; then
	echo "$progname: no uid can be allocated in $minuid..$maxuid" 1>&2
	$rmprog -f $ptmp
	exit 1
fi

case "${name}" in
*$)	: ${comment:=${name%%[$]*} samba machine account} ;;
*)	: ${comment:=${name} samba user} ;;
esac
entry="${name}:*:${uid}:${gid}::0:0:${comment}:${homedir}:${shell}"

echo "$entry" >> $ptmp

$doit $pwdmkdbprog -p -u "${name}" $ptmp
rc=$?

$rmprog -f $ptmp
exit $rc
