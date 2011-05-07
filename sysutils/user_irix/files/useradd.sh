#!/bin/sh

show_usage () {
    echo "usage: useradd [-g gid] [-u uid] [-s shell] [-c comment] [-d home-dir] user" >&2
    exit 1
}

shquote (){
    __cmd=`printf '%s\n' "$1" | sed "s|'|'\\\\\''|g"`
    printf "%s\n" "'$__cmd'"
}

while getopts 'g:u:s:c:d:' f; do
    case $f in
	g)
	    gid="$OPTARG"
	    if echo "$gid" | grep '^[0-9]*$' > /dev/null; then
		:
	    else
		gid=`awk -F: -v name="$gid" '$1 == name {print $3; exit}' /etc/group`
	    fi
	    opts="$opts -g $gid";;
	u)	opts="$opts -u "`shquote "$OPTARG"`;;
	s)	opts="$opts -s "`shquote "$OPTARG"`;;
	c)	opts="$opts -c "`shquote "$OPTARG"`;;
	d)	opts="$opts -h "`shquote "$OPTARG"`;;
	\?)	show_usage;;
    esac
done
shift $(($OPTIND - 1))

if test $# -ne 1; then
    show_usage
    exit 1
fi

eval "/usr/sbin/passmgmt -a $opts $1"
