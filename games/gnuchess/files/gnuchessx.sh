#!/bin/sh
#
# $NetBSD: gnuchessx.sh,v 1.2 2001/11/11 07:54:55 jlam Exp $
#
# Wrapper script for gnuchess to interface with xboard.

exec @PREFIX@/bin/gnuchess xboard $*
