#!/bin/sh
#
# $NetBSD: raidutil.sh,v 1.1.1.1 2001/09/26 07:28:49 ad Exp $
#
DPTMGR_HOME=@PREFIX@/lib/dpt
LD_LIBRARY_PATH=$DPTMGR_HOME:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
exec ${DPTMGR_HOME}/raidutil "$@"
