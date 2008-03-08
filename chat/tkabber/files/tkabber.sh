#!/bin/sh
#
# $NetBSD: tkabber.sh,v 1.1.1.1 2008/03/08 18:57:38 reed Exp $

exec @WISH@ @DATADIR@/tkabber.tcl -name tkabber "$$@"
