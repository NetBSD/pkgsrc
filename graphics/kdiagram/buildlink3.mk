# $NetBSD: buildlink3.mk,v 1.16 2026/05/14 16:41:12 ryoon Exp $

BUILDLINK_TREE+=	kdiagram

.if !defined(KDIAGRAM_BUILDLINK3_MK)
KDIAGRAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdiagram+=	kdiagram>=2.8.0
BUILDLINK_ABI_DEPENDS.kdiagram?=	kdiagram>=3.0.1nb3
BUILDLINK_PKGSRCDIR.kdiagram?=		../../graphics/kdiagram

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDIAGRAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdiagram
