#!/bin/sh

# $NetBSD: root.sh,v 1.1.1.1 1999/11/17 16:17:03 drochner Exp $

ROOTSYS=XXXPREFIXXXX/root
export ROOTSYS
PATH=XXXPREFIXXXX/root/bin:${PATH}
exec XXXPREFIXXXX/root/bin/`basename $0` $*
