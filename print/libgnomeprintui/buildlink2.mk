# $NetBSD: buildlink2.mk,v 1.11 2003/12/14 19:51:29 jmmv Exp $
#
# This Makefile fragment is included by packages that use libgnomeprintui.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBGNOMEPRINTUI_BUILDLINK2_MK)
LIBGNOMEPRINTUI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgnomeprintui
BUILDLINK_DEPENDS.libgnomeprintui?=	libgnomeprintui>=2.4.0
BUILDLINK_PKGSRCDIR.libgnomeprintui?=	../../print/libgnomeprintui

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgnomeprintui=libgnomeprintui
BUILDLINK_PREFIX.libgnomeprintui_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgnomeprintui+=	include/libgnomeprintui-2.2/libgnomeprintui/*
BUILDLINK_FILES.libgnomeprintui+=	lib/libgnomeprintui-2-2.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
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
