# $NetBSD: buildlink2.mk,v 1.1 2003/01/28 01:15:45 uebayasi Exp $
#
# This Makefile fragment is included by packages that use superlu.
#

.if !defined(SUPERLU_BUILDLINK2_MK)
SUPERLU_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			superlu
BUILDLINK_DEPENDS.superlu?=		superlu>=2.0nb2
BUILDLINK_PKGSRCDIR.superlu?=		../../math/superlu

EVAL_PREFIX+=	BUILDLINK_PREFIX.superlu=superlu
BUILDLINK_PREFIX.superlu_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.superlu+=	include/superlu/*.h
BUILDLINK_FILES.superlu+=	lib/libsuperlu.*

# Users need to manually set
#	CPPFLAGS+=	${BUILDLINK_CPPFLAGS.superlu}
BUILDLINK_CPPFLAGS.superlu+=	-I${BUILDLINK_PREFIX.superlu}/include/superlu

BUILDLINK_TARGETS+=	superlu-buildlink

superlu-buildlink: _BUILDLINK_USE

.endif	# SUPERLU_BUILDLINK2_MK
