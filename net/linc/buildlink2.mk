# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:38 jlam Exp $

.if !defined(LINC_BUILDLINK2_MK)
LINC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		linc
BUILDLINK_DEPENDS.linc?=	linc>=0.1.21nb1
BUILDLINK_PKGSRCDIR.linc?=	../../net/linc

EVAL_PREFIX+=		BUILDLINK_PREFIX.linc=linc
BUILDLINK_PREFIX.linc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.linc=	include/linc-1.0/linc/*
BUILDLINK_FILES.linc+=	lib/liblinc.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	linc-buildlink

linc-buildlink: _BUILDLINK_USE

.endif	# LINC_BUILDLINK2_MK
