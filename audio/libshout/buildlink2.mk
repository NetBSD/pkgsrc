# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/12 03:56:19 kim Exp $

.if !defined(LIBSHOUT_BUILDLINK2_MK)
LIBSHOUT_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=		libshout
BUILDLINK_DEPENDS.libshout?=	libshout>=2.0
BUILDLINK_PKGSRCDIR.libshout?=	../../audio/libshout

EVAL_PREFIX+=	BUILDLINK_PREFIX.libshout=libshout
BUILDLINK_PREFIX.libshout=	${LOCALBASE}
BUILDLINK_FILES.libshout+=	bin/shout-config
BUILDLINK_FILES.libshout+=	include/shout/*
BUILDLINK_FILES.libshout+=	lib/libshout.*

.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=		libshout-buildlink

libshout-buildlink: _BUILDLINK_USE

.endif	# LIBSHOUT_BUILDLINK2_MK
