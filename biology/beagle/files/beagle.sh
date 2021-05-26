#!/bin/sh
# $NetBSD: beagle.sh,v 1.1 2021/05/26 19:13:39 brook Exp $
#
# run beagle
#

exec @JAVA_BINPREFIX@-java -jar @PREFIX@/libexec/beagle/beagle.21Apr21.304.jar ${*}
