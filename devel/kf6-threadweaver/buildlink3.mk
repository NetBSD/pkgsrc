# $NetBSD: buildlink3.mk,v 1.7 2025/08/22 13:24:07 wiz Exp $

BUILDLINK_TREE+=	kf6-threadweaver

.if !defined(KF6_THREADWEAVER_BUILDLINK3_MK)
KF6_THREADWEAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-threadweaver+=	kf6-threadweaver>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-threadweaver?=	kf6-threadweaver>=6.8.0nb2
BUILDLINK_PKGSRCDIR.kf6-threadweaver?=		../../devel/kf6-threadweaver

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_THREADWEAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-threadweaver
