# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:21:52 jlam Exp $

.if !defined(LIBMIKMOD_BUILDLINK2_MK)
LIBMIKMOD_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_PACKAGES+=		libmikmod
BUILDLINK_DEPENDS.libmikmod?=	libmikmod>=3.1.9
BUILDLINK_PKGSRCDIR.libmikmod?=	../../audio/libmikmod

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmikmod=libmikmod
BUILDLINK_PREFIX.libmikmod_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmikmod=	include/mikmod.h
BUILDLINK_FILES.libmikmod+=	lib/libmikmod.*

BUILDLINK_TARGETS+=	libmikmod-buildlink

libmikmod-buildlink: _BUILDLINK_USE

.endif	# LIBMIKMOD_BUILDLINK2_MK
