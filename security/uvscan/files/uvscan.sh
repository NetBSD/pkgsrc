#!/bin/sh
#
# $NetBSD: uvscan.sh,v 1.2 2001/08/16 05:09:22 jlam Exp $
#
# Wrapper script to execute McAfee(R) VirusScan

@PREFIX@/libexec/uvscan/uvscan $*
