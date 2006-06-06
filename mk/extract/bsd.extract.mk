# $NetBSD: bsd.extract.mk,v 1.1 2006/06/06 03:05:48 jlam Exp $
#
# This Makefile fragment is included to bsd.pkg.mk and defines the
# relevant variables and targets for the "extract" phase.
#
# The following are the "public" targets provided by this module:
#
#    extract
#
# The following targets may be overridden in a package Makefile:
#
#    pre-extract, do-extract, post-extract
#

.include "${PKGSRCDIR}/mk/extract/extract.mk"
