#!/bin/sh
#
# $NetBSD: uvscan.sh,v 1.4 2007/07/29 05:19:51 jlam Exp $
#
# Wrapper script to execute McAfee(R) VirusScan

LD_LIBRARY_PATH=@PREFIX@/libexec/uvscan @PREFIX@/libexec/uvscan/uvscan "$@"
