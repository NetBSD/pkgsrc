# $NetBSD: buildlink3.mk,v 1.17 2026/09/02 19:02:42 wiz Exp $

BUILDLINK_TREE+=	kdiagram

.if !defined(KDIAGRAM_BUILDLINK3_MK)
KDIAGRAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdiagram+=	kdiagram>=2.8.0
BUILDLINK_ABI_DEPENDS.kdiagram?=	kdiagram>=3.0.1nb4
BUILDLINK_PKGSRCDIR.kdiagram?=		../../graphics/kdiagram

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDIAGRAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdiagram
