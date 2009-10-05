#!/bin/sh
#
# $NetBSD: show-buildlink3.sh,v 1.3 2009/10/05 02:40:06 obache Exp $
#
# This script is a helper for the show-buildlink3 target and outputs
# the arguments as tree.
#

while test $# -gt 0; do
	pkg="$1"
	case $pkg in
	-*)
		indentation=${indentation#    }
		;;
	*)
		echo "${indentation}${pkg}"
		indentation="${indentation}    "
		;;
	esac
	shift
done
