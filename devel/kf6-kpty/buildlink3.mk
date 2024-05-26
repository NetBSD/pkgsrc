# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:02:20 markd Exp $

BUILDLINK_TREE+=	kf6-kpty

.if !defined(KF6_KPTY_BUILDLINK3_MK)
KF6_KPTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kpty+=	kf6-kpty>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kpty?=		../../devel/kf6-kpty

.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KPTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kpty
