#!/bin/sh
# $NetBSD: etded.sh,v 1.1.1.1 2004/07/08 14:28:37 xtraeme Exp $

cd @PREFIX@/lib/lokigames/et
exec ./etded.x86 "$@"
