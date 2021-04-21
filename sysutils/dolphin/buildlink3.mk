# $NetBSD: buildlink3.mk,v 1.3 2021/04/21 11:40:38 adam Exp $

BUILDLINK_TREE+=	dolphin

.if !defined(DOLPHIN_BUILDLINK3_MK)
DOLPHIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dolphin+=	dolphin>=16.04.0
BUILDLINK_ABI_DEPENDS.dolphin?=	dolphin>=20.12.3nb1
BUILDLINK_PKGSRCDIR.dolphin?=	../../sysutils/dolphin

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# DOLPHIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-dolphin
