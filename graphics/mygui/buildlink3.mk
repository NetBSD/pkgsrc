# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:50 wiz Exp $

BUILDLINK_TREE+=	mygui

.if !defined(MYGUI_BUILDLINK3_MK)
MYGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mygui+=	mygui>=3.2.2
BUILDLINK_ABI_DEPENDS.mygui?=	mygui>=3.2.3.20190707nb1
BUILDLINK_PKGSRCDIR.mygui?=	../../graphics/mygui

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.endif	# MYGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-mygui
