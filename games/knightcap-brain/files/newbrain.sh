#!/bin/sh

BRAIN_FILE=@PREFIX@/share/examples/knightcap/brain.dat

args=`getopt f $*`
if [ $? != 0 ]
then
	echo 'Usage: newbrain [-f] [directory]'
	exit 2
fi

force=0

set -- $args
for arg
do
	shift
	case "$arg" in
	-f)	force=1 ;;
	--)	break ;;
	esac
done

dir=${1:-.}	# default to copying brain to current directory

if [ -f ${dir}/brain.dat -a ${force} -eq 0 ]
then
	echo "The file ${dir}/brain.dat already exists."
	echo "Please move it out of the way, or use another directory."
	exit 0
fi

install -c -m 644 ${BRAIN_FILE} ${dir}
