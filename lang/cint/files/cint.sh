#!/bin/sh

# $NetBSD: cint.sh,v 1.1.1.1 1999/11/17 14:48:18 drochner Exp $

CINTSYSDIR=XXXPREFIXXXX/cint
export CINTSYSDIR
exec XXXPREFIXXXX/cint/`basename $0` $*
