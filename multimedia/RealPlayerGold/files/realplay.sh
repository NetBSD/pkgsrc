#!/bin/sh
#
#	$NetBSD: realplay.sh,v 1.1.1.1 2004/11/20 12:45:40 rh Exp $
#
HELIX_LIBS=@REALPLAYER_HOME@ ; export HELIX_LIBS
LD_LIBRARY_PATH=${HELIX_LIBS}/lib:${HELIX_LIBS}/plugins:${HELIX_LIBS}:${LD_LIBRARY_PATH} ; export LD_LIBRARY_PATH
exec ${HELIX_LIBS}/realplay "$@"
