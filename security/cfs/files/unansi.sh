#!/bin/sh
#
# We need to disable ANSI prototypes for the rpcgen'd functions because of
# the way the build script redefines some functions in terms of other
# functions which have different prototypes.

case $1 in
NetBSD)
	set -e
	@AWK@ '
	/__STDC__/	{ last = NR - 1 }
			{ lines[linec++] = $0 }
	END {
		gsub("__STDC__", "__STDC__XXX", lines[last]);
		for (i = 0; i < linec; i++)
			print lines[i]
	}' < $2 > $2.tmp
	@MV@ -f $2.tmp $2
	;;
*)
	;;
esac
