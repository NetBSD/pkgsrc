# $NetBSD: buildlink2.mk,v 1.3 2002/12/27 06:29:20 uebayasi Exp $

.if !defined(SJ3_BUILDLINK2_MK)
SJ3_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sj3
BUILDLINK_DEPENDS.sj3?=		sj3-lib>=2.0.1.20nb1
BUILDLINK_PKGSRCDIR.sj3?=	../../inputmethod/sj3-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.sj3=sj3-lib
BUILDLINK_PREFIX.sj3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sj3=		include/sj3lib.h
BUILDLINK_FILES.sj3+=		lib/libsj3lib.a

BUILDLINK_TARGETS+=	sj3-buildlink

sj3-buildlink: _BUILDLINK_USE

.endif	# SJ3_BUILDLINK2_MK
