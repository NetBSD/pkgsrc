#!/bin/sh
#
# $NetBSD: show-buildlink3.sh,v 1.4 2016/07/10 07:08:21 rillig Exp $
#
# This script is a helper for the show-buildlink3 target and outputs
# the arguments as tree.
#

indentation=""
for pkg in "$@"; do
	case $pkg in
	-*)
		indentation=${indentation#    }
		;;
	*)
		echo "${indentation}${pkg}"
		indentation="${indentation}    "
		;;
	esac
done
