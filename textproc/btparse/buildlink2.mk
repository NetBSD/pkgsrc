# $NetBSD: buildlink2.mk,v 1.2 2002/11/01 04:25:19 rh Exp $
#
# This Makefile fragment is included by packages that use btparse.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(BTPARSE_BUILDLINK2_MK)
BTPARSE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			btparse
BUILDLINK_DEPENDS.btparse?=		btparse>=0.33
BUILDLINK_PKGSRCDIR.btparse?=		../../textproc/btparse

EVAL_PREFIX+=	BUILDLINK_PREFIX.btparse=btparse
BUILDLINK_PREFIX.btparse_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.btparse+=	include/btparse.h
BUILDLINK_FILES.btparse+=	lib/libbtparse.*

BUILDLINK_TARGETS+=	btparse-buildlink

btparse-buildlink: _BUILDLINK_USE

.endif	# BTPARSE_BUILDLINK2_MK
