# $NetBSD: buildlink3.mk,v 1.25 2026/09/27 11:38:34 tnn Exp $

BUILDLINK_TREE+=	dolphin

.if !defined(DOLPHIN_BUILDLINK3_MK)
DOLPHIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dolphin+=	dolphin>=16.04.0
BUILDLINK_ABI_DEPENDS.dolphin?=	dolphin>=26.08.0nb1
BUILDLINK_PKGSRCDIR.dolphin?=	../../sysutils/dolphin

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# DOLPHIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-dolphin
