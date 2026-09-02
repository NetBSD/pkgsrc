# $NetBSD: buildlink3.mk,v 1.2 2026/09/02 19:03:30 wiz Exp $

BUILDLINK_TREE+=	kdsingleapplication

.if !defined(KDSINGLEAPPLICATION_BUILDLINK3_MK)
KDSINGLEAPPLICATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdsingleapplication+=	kdsingleapplication>=1.2.1
BUILDLINK_ABI_DEPENDS.kdsingleapplication?=	kdsingleapplication>=1.2.1nb1
BUILDLINK_PKGSRCDIR.kdsingleapplication?=	../../misc/kdsingleapplication

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KDSINGLEAPPLICATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdsingleapplication
