# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:32 jlam Exp $

.if !defined(GB_BUILDLINK2_MK)
GB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gb
BUILDLINK_DEPENDS.gb?=		gb>=0.0.20nb1
BUILDLINK_PKGSRCDIR.gb?=	../../lang/gb

EVAL_PREFIX+=			BUILDLINK_PREFIX.gb=gb
BUILDLINK_PREFIX.gb_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gb=		include/gb/*
BUILDLINK_FILES.gb+=		include/gbrun/*
BUILDLINK_FILES.gb+=		lib/libgbrun.*

.include "../../print/gnome-print/buildlink2.mk"

BUILDLINK_TARGETS+=	gb-buildlink

gb-buildlink: _BUILDLINK_USE

.endif	# GB_BUILDLINK2_MK
