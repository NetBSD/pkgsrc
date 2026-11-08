# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 16:40:18 ryoon Exp $

BUILDLINK_TREE+=	raygui

.if !defined(RAYGUI_BUILDLINK3_MK)
RAYGUI_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.raygui?=	build

BUILDLINK_API_DEPENDS.raygui+=	raygui>=5.0
BUILDLINK_PKGSRCDIR.raygui?=	../../devel/raygui
.endif	# RAYGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-raygui
