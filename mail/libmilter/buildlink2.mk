# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/23 13:03:31 markd Exp $
#
# This Makefile fragment is included by packages that use libmilter.
#

.if !defined(LIBMILTER_BUILDLINK2_MK)
LIBMILTER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libmilter
BUILDLINK_DEPENDS.libmilter?=		libmilter>=8.12.6
BUILDLINK_PKGSRCDIR.libmilter?=		../../mail/libmilter

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmilter=libmilter
BUILDLINK_PREFIX.libmilter_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmilter+=	include/libmilter/mfapi.h
BUILDLINK_FILES.libmilter+=	include/libmilter/mfdef.h
BUILDLINK_FILES.libmilter+=	lib/libmilter.*

BUILDLINK_TARGETS+=	libmilter-buildlink

libmilter-buildlink: _BUILDLINK_USE

.endif	# LIBMILTER_BUILDLINK2_MK
