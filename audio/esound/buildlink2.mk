# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:05 jlam Exp $

.if !defined(ESOUND_BUILDLINK2_MK)
ESOUND_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		esound
BUILDLINK_DEPENDS.esound?=	esound>=0.2.18
BUILDLINK_PKGSRCDIR.esound?=	../../audio/esound

EVAL_PREFIX+=	BUILDLINK_PREFIX.esound=esound
BUILDLINK_PREFIX.esound_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.esound=		include/esd.h
BUILDLINK_FILES.esound+=	lib/libesd.*

.include "../../audio/libaudiofile/buildlink2.mk"

BUILDLINK_TARGETS+=		esound-buildlink

esound-buildlink: _BUILDLINK_USE

.endif	# ESOUND_BUILDLINK2_MK
