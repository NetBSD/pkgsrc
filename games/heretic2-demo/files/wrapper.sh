#!/bin/sh -e
# $NetBSD: wrapper.sh,v 1.1.1.1 2000/10/16 12:24:58 abs Exp $
# Simple wrapper for lokigames @@BINNAME@@

# linux binary calls mkdir for this with a trailing '/'
if [ ! -d $HOME/.loki ];then
    mkdir $HOME/.loki
fi
cd @@LIBDIR@@
exec ./@@BINNAME@@ $@
