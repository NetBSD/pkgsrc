# $NetBSD: buildlink2.mk,v 1.7 2003/12/08 14:42:44 wiz Exp $

.if !defined(FLAC_BUILDLINK2_MK)
FLAC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			flac
BUILDLINK_DEPENDS.flac?=		flac>=1.1.0nb1
BUILDLINK_PKGSRCDIR.flac?=		../../audio/flac

EVAL_PREFIX+=	BUILDLINK_PREFIX.flac=flac
BUILDLINK_PREFIX.flac_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.flac+=	include/FLAC++/*.h
BUILDLINK_FILES.flac+=	include/FLAC/*.h
BUILDLINK_FILES.flac+=	include/OggFLAC++/*.h
BUILDLINK_FILES.flac+=	include/OggFLAC/*.h
BUILDLINK_FILES.flac+=	lib/libFLAC++.*
BUILDLINK_FILES.flac+=	lib/libFLAC.*
BUILDLINK_FILES.flac+=	lib/libOggFLAC++.*
BUILDLINK_FILES.flac+=	lib/libOggFLAC.*

.include "../../audio/libogg/buildlink2.mk"

BUILDLINK_TARGETS+=	flac-buildlink

flac-buildlink: _BUILDLINK_USE

.endif	# FLAC_BUILDLINK2_MK
