# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/21 23:00:32 jlam Exp $

.if !defined(LIBUNGIF_BUILDLINK2_MK)
LIBUNGIF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libungif
BUILDLINK_DEPENDS.libungif?=	libungif>=4.1.0
BUILDLINK_PKGSRCDIR.libungif?=	../../graphics/libungif

EVAL_PREFIX+=	BUILDLINK_PREFIX.libungif=libungif
BUILDLINK_PREFIX.libungif_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libungif=	include/gif_lib.h
BUILDLINK_FILES.libungif+=	lib/libgif.*
BUILDLINK_FILES.libungif+=	lib/libungif.*

BUILDLINK_TARGETS+=		libungif-buildlink

libungif-buildlink: _BUILDLINK_USE

.endif	# LIBUNGIF_BUILDLINK2_MK
