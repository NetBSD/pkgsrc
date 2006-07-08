# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:11:05 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEPRINTUI_BUILDLINK3_MK:=	${LIBGNOMEPRINTUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeprintui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomeprintui}
BUILDLINK_PACKAGES+=	libgnomeprintui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgnomeprintui

.if !empty(LIBGNOMEPRINTUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.8.0
BUILDLINK_ABI_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.12.1nb3
BUILDLINK_PKGSRCDIR.libgnomeprintui?=	../../print/libgnomeprintui
.endif	# LIBGNOMEPRINTUI_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
