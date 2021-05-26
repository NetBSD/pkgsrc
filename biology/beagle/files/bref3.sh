#!/bin/sh
# $NetBSD: bref3.sh,v 1.1 2021/05/26 19:13:39 brook Exp $
#
# run bref3
#

exec @JAVA_BINPREFIX@-java -jar @PREFIX@/libexec/beagle/bref3.21Apr21.304.jar ${*}
