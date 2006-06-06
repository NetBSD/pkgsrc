# $NetBSD: bsd.fetch.mk,v 1.1 2006/06/06 03:05:48 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines the
# relevant variables and targets for the "fetch" step.
#

.include "${PKGSRCDIR}/mk/fetch/sites.mk"
.include "${PKGSRCDIR}/mk/fetch/fetch.mk"
.include "${PKGSRCDIR}/mk/fetch/distclean.mk"
