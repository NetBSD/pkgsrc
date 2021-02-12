# $NetBSD: buildlink3.mk,v 1.2 2021/02/12 14:35:55 wiz Exp $

BUILDLINK_TREE+=	dolphin

.if !defined(DOLPHIN_BUILDLINK3_MK)
DOLPHIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dolphin+=	dolphin>=16.04.0
BUILDLINK_PKGSRCDIR.dolphin?=	../../sysutils/dolphin

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# DOLPHIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-dolphin
