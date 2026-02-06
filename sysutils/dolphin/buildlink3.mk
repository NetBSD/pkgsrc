# $NetBSD: buildlink3.mk,v 1.22 2026/02/06 10:05:52 wiz Exp $

BUILDLINK_TREE+=	dolphin

.if !defined(DOLPHIN_BUILDLINK3_MK)
DOLPHIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dolphin+=	dolphin>=16.04.0
BUILDLINK_ABI_DEPENDS.dolphin?=	dolphin>=25.08.3nb2
BUILDLINK_PKGSRCDIR.dolphin?=	../../sysutils/dolphin

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# DOLPHIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-dolphin
