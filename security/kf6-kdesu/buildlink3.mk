# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:46:46 markd Exp $

BUILDLINK_TREE+=	kf6-kdesu

.if !defined(KF6_KDESU_BUILDLINK3_MK)
KF6_KDESU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kdesu+=	kf6-kdesu>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kdesu?=		../../security/kf6-kdesu

.include "../../devel/kf6-kpty/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KDESU_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kdesu
