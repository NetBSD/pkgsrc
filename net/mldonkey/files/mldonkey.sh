#!/bin/sh
#
# $NetBSD: mldonkey.sh,v 1.2 2003/05/19 12:52:59 wiz Exp $
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
@PREFIX@/libexec/mldonkey/mlnet > $HOME/mldonkey/log 2>&1
