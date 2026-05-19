# $NetBSD: buildlink3.mk,v 1.1 2026/05/19 14:32:28 adam Exp $

BUILDLINK_TREE+=	kdsingleapplication

.if !defined(KDSINGLEAPPLICATION_BUILDLINK3_MK)
KDSINGLEAPPLICATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsingleapplication+=	kdsingleapplication>=1.2.1
BUILDLINK_PKGSRCDIR.kdsingleapplication?=	../../misc/kdsingleapplication

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDSINGLEAPPLICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsingleapplication
