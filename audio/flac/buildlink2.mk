# $NetBSD: buildlink2.mk,v 1.5 2002/11/10 23:55:14 lukem Exp $

.if !defined(FLAC_BUILDLINK2_MK)
FLAC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		flac
BUILDLINK_DEPENDS.flac?=	flac>=1.0.4
BUILDLINK_PKGSRCDIR.flac?=	../../audio/flac

EVAL_PREFIX+=			BUILDLINK_PREFIX.flac=flac
BUILDLINK_PREFIX.flac_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.flac=		include/FLAC/*
BUILDLINK_FILES.flac+=		include/FLAC++/*
BUILDLINK_FILES.flac+=		lib/libFLAC.*
BUILDLINK_FILES.flac+=		lib/libFLAC++.*

BUILDLINK_TARGETS+=	flac-buildlink

flac-buildlink: _BUILDLINK_USE

.endif	# FLAC_BUILDLINK2_MK
