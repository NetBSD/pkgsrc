#!/bin/sh
#
# $NetBSD: mldonkey.sh,v 1.1.1.1 2003/03/31 15:55:36 jmmv Exp $
#
# pkgsrc script to ease mldonkey's startup.
#

if [ ! -d $HOME/mldonkey ]; then
	echo "Creating user's directory ($HOME/mldonkey)..."
	mkdir $HOME/mldonkey
fi

echo "Starting mldonkey..."
cd $HOME/mldonkey
PATH=@PREFIX@/libexec/mldonkey:$PATH
@PREFIX@/libexec/mldonkey/mldonkey > $HOME/mldonkey/log 2>&1
