# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 02:34:55 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgnomeprintui.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGNOMEPRINTUI_BUILDLINK3_MK:=	${LIBGNOMEPRINTUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeprintui
.endif

.if !empty(LIBGNOMEPRINTUI_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgnomeprintui
BUILDLINK_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.4.2nb1
BUILDLINK_PKGSRCDIR.libgnomeprintui?=	../../print/libgnomeprintui

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif # LIBGNOMEPRINTUI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
