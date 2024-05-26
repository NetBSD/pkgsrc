# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:06:59 markd Exp $

BUILDLINK_TREE+=	kf6-kservice

.if !defined(KF6_KSERVICE_BUILDLINK3_MK)
KF6_KSERVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kservice+=	kf6-kservice>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kservice?=	../../devel/kf6-kservice

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KSERVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kservice
