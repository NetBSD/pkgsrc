# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:03 jlam Exp $
#
# This Makefile fragment is included by packages that use ltdl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.ltdl to the dependency pattern
#     for the version of libtool-base desired.
# (1) Include this Makefile fragment in the package Makefile.

.if !defined(LTDL_BUILDLINK2_MK)
LTDL_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.ltdl?=	libtool-base>=${LIBTOOL_REQD}
DEPENDS+=	${BUILDLINK_DEPENDS.ltdl}:../../devel/libtool-base

BUILDLINK_PREFIX.ltdl=	${LOCALBASE}
BUILDLINK_FILES.ltdl=	include/ltdl.h
BUILDLINK_FILES.ltdl+=	lib/libltdl.*

BUILDLINK_TARGETS+=	ltdl-buildlink

ltdl-buildlink: _BUILDLINK_USE

.endif	# LTDL_BUILDLINK2_MK
