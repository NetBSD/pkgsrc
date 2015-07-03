#!/bin/sh
# $NetBSD: yed.sh,v 1.1.1.1 2015/07/03 09:56:55 abs Exp $
exec java -jar @YEDDIR@/yed.jar "$@"
