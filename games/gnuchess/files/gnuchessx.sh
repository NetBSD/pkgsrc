#!/bin/sh
#
# $NetBSD: gnuchessx.sh,v 1.1 2000/03/26 08:29:25 jlam Exp $
#
# Wrapper script for gnuchess to interface with xboard.

exec @PREFIX@/bin/gnuchess xboard
