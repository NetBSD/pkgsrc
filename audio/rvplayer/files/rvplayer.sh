#!/bin/sh
#
# $NetBSD: rvplayer.sh,v 1.1.1.1 1999/08/29 01:32:27 jlam Exp $
#
REAL_HOME=@@REAL_HOME@@ ; export REAL_HOME
LD_LIBRARY_PATH=${REAL_HOME}:${LD_LIBRARY_PATH} ; export LD_LIBRARY_PATH
exec ${REAL_HOME}/rvplayer "$@"
