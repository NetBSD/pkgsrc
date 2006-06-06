# $NetBSD: bsd.patch.mk,v 1.1 2006/06/06 04:48:19 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "patch" phase.
#
# The following are the "public" targets provided by this module:
#
#    patch
#
# The following targets may be overridden in a package Makefile:
#
#    pre-patch, do-patch, post-patch
#

.include "${PKGSRCDIR}/mk/patch/patch.mk"
