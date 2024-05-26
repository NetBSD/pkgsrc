# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:48:51 markd Exp $

BUILDLINK_TREE+=	kf6-knotifyconfig

.if !defined(KF6_KNOTIFYCONFIG_BUILDLINK3_MK)
KF6_KNOTIFYCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-knotifyconfig+=	kf6-knotifyconfig>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-knotifyconfig?=		../../devel/kf6-knotifyconfig

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KNOTIFYCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-knotifyconfig
