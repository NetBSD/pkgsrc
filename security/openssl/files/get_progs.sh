#!/bin/sh
# Help figure out what programs openssl wants to install.
# Use when updating this package.
#
export SCRIPTS="`grep ^SCRIPTS= apps/Makefile | sed -es/^SCRIPTS=//`"
export PROGRAM="`grep ^PROGRAM= apps/Makefile | sed -es/^PROGRAM=//`"
export APPS="`grep ^APPS= tools/Makefile | sed -es/^APPS=//`"
export MISC_APPS="`grep ^MISC_APPS= tools/Makefile | sed -es/^MISC_APPS=//`"
(for f in $SCRIPTS $PROGRAM $APPS $MISC_APPS ; do
    echo bin/$f
done ;
grep FUNC_TYPE apps/progs.h | awk ' BEGIN { FS="," } { print $2 }' | sed -e's/\"//g' -e's,^,bin/,') \
	| sort | uniq | awk ' /^bin\/.+/ { print }'
