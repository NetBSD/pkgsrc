# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:50 jlam Exp $
#
# This Makefile fragment is included by packages that use rsaref.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.rsaref to the dependency pattern
#     for the version of rsaref desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(RSAREF_BUILDLINK2_MK)
RSAREF_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.rsaref?=	rsaref-2.0p3
DEPENDS+=	${BUILDLINK_DEPENDS.rsaref}:../../security/rsaref

EVAL_PREFIX+=	BUILDLINK_PREFIX.rsaref=rsaref
BUILDLINK_PREFIX.rsaref_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rsaref=		include/rsaref/*.h
BUILDLINK_FILES.rsaref+=	lib/librsaref.*

BUILDLINK_TARGETS+=	rsaref-buildlink

rsaref-buildlink: _BUILDLINK_USE

.endif	# RSAREF_BUILDLINK2_MK
