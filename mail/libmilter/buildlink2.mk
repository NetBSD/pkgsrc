# $NetBSD: buildlink2.mk,v 1.2 2003/05/02 11:55:39 wiz Exp $
#
# This Makefile fragment is included by packages that use libmilter.
#

.if !defined(LIBMILTER_BUILDLINK2_MK)
LIBMILTER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libmilter
BUILDLINK_DEPENDS.libmilter?=		libmilter>=8.12.9nb1
BUILDLINK_PKGSRCDIR.libmilter?=		../../mail/libmilter

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmilter=libmilter
BUILDLINK_PREFIX.libmilter_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmilter+=	include/libmilter/mfapi.h
BUILDLINK_FILES.libmilter+=	include/libmilter/mfdef.h
BUILDLINK_FILES.libmilter+=	lib/libmilter.*

BUILDLINK_TARGETS+=	libmilter-buildlink

libmilter-buildlink: _BUILDLINK_USE

.endif	# LIBMILTER_BUILDLINK2_MK
