#!/bin/sh -e
# $NetBSD: wrapper.sh,v 1.2 2002/03/12 15:01:35 abs Exp $
# Simple wrapper for lokigames @@BINNAME@@

# linux binary calls mkdir for this with a trailing '/'
if [ ! -d $HOME/.loki ];then
    mkdir $HOME/.loki
fi
cd @@LIBDIR@@
exec ./@@BINNAME@@ "$@"
