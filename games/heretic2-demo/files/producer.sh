#!/bin/sh -e
# $NetBSD: producer.sh,v 1.1 2002/10/18 19:12:05 abs Exp $
# Simple wrapper for real producer

ulimit -n 256
exec @@PREFIX@@/lib/real/producer/producer "$@"
