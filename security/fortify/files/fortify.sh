#!/bin/sh
#
# $NetBSD: fortify.sh,v 1.1.1.1 1999/10/28 00:02:08 jlam Exp $

cd @PREFIX@/share/fortify
exec @PREFIX@/libexec/fortify $*
