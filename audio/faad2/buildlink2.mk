# $NetBSD: buildlink2.mk,v 1.2 2004/03/28 20:16:09 mycroft Exp $

.if !defined(FAAD2_BUILDLINK2_MK)
FAAD2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			faad2
BUILDLINK_DEPENDS.faad2?=		faad2>=2.0
BUILDLINK_PKGSRCDIR.faad2?=	../../audio/faad2

EVAL_PREFIX+=	BUILDLINK_PREFIX.faad2=faad2
BUILDLINK_PREFIX.faad2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.faad2+=	include/faad.h
BUILDLINK_FILES.faad2+=	lib/libfaad.*
BUILDLINK_FILES.faad2+=	lib/libmp4v2.*

BUILDLINK_TARGETS+=	faad2-buildlink

faad2-buildlink: _BUILDLINK_USE

.endif	# FAAD2_BUILDLINK2_MK
