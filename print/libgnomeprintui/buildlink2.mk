# $NetBSD: buildlink2.mk,v 1.2 2002/09/22 09:52:37 jlam Exp $

.if !defined(LIBGNOMEPRINTUI_BUILDLINK2_MK)
LIBGNOMEPRINTUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgnomeprintui
BUILDLINK_DEPENDS.libgnomeprintui?=	libgnomeprintui>=1.116.0
BUILDLINK_PKGSRCDIR.libgnomeprintui?=	../../print/libgnomeprintui

EVAL_PREFIX+=		BUILDLINK_PREFIX.libgnomeprintui=libgnomeprintui
BUILDLINK_PREFIX.libgnomeprintui_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libgnomeprintui=	include/libgnomeprintui-2.0/libgnomeprintui/*
BUILDLINK_FILES.libgnomeprintui+=	lib/libgnomeprintui-2.*

.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgnomeprintui-buildlink

libgnomeprintui-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMEPRINTUI_BUILDLINK2_MK
