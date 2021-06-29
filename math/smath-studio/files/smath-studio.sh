#!/bin/sh
#
# Start SMath Studio with mono runtime
#
# $NetBSD: smath-studio.sh,v 1.1 2021/06/29 14:28:12 hauke Exp $

exec @PREFIX@/bin/mono "@PREFIX@/@SMATH_DIR@/SMathStudio_Desktop.exe" "$@"
