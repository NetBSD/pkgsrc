#!/bin/sh -e
# $NetBSD: wrapper.sh,v 1.1.1.1 2003/06/19 16:44:07 wiz Exp $
# Simple wrapper for lgp's @@BINNAME@@

# Linux binary calls mkdir for this with a trailing '/'
if [ ! -d $HOME/.lgp ];then
    mkdir $HOME/.lgp
fi
if [ ! -d $HOME/.lgp/maj_demo ];then
    mkdir $HOME/.lgp/maj_demo
fi
cd @@LIBDIR@@
exec ./@@BINNAME@@ "$@"
