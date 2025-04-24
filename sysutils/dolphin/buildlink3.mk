# $NetBSD: buildlink3.mk,v 1.18 2025/04/24 14:15:44 wiz Exp $

BUILDLINK_TREE+=	dolphin

.if !defined(DOLPHIN_BUILDLINK3_MK)
DOLPHIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dolphin+=	dolphin>=16.04.0
BUILDLINK_ABI_DEPENDS.dolphin?=	dolphin>=23.08.4nb10
BUILDLINK_PKGSRCDIR.dolphin?=	../../sysutils/dolphin

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# DOLPHIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-dolphin
