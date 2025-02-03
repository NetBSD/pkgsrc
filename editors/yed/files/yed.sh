#!/bin/sh
# $NetBSD: yed.sh,v 1.3 2025/02/03 13:11:51 wiz Exp $
exec java -jar @YEDDIR@/yed.jar "$@"
