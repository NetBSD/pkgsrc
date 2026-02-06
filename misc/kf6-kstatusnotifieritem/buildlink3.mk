# $NetBSD: buildlink3.mk,v 1.6 2026/02/06 10:05:20 wiz Exp $

BUILDLINK_TREE+=	kf6-kstatusnotifieritem

.if !defined(KF6_KSTATUSNOTIFIERITEM_BUILDLINK3_MK)
KF6_KSTATUSNOTIFIERITEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kstatusnotifieritem+=	kf6-kstatusnotifieritem>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kstatusnotifieritem?=	kf6-kstatusnotifieritem>=6.18.0nb3
BUILDLINK_PKGSRCDIR.kf6-kstatusnotifieritem?=	../../misc/kf6-kstatusnotifieritem

.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KSTATUSNOTIFIERITEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kstatusnotifieritem
