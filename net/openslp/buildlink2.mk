# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:45 jlam Exp $
#
# This Makefile fragment is included by packages that use openslp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.openslp to the dependency pattern
#     for the version of openslp desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(OPENSLP_BUILDLINK2_MK)
OPENSLP_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.openslp?=	openslp>=1.0.1
DEPENDS+=	${BUILDLINK_DEPENDS.openslp}:../../net/openslp

EVAL_PREFIX+=	BUILDLINK_PREFIX.openslp=openslp
BUILDLINK_PREFIX.openslp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openslp=	include/slp.h
BUILDLINK_FILES.openslp+=	lib/libslp.*

BUILDLINK_TARGETS+=	openslp-buildlink

openslp-buildlink: _BUILDLINK_USE

.endif	# OPENSLP_BUILDLINK2_MK
