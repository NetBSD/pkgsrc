# $NetBSD: buildlink3.mk,v 1.11 2026/09/02 19:01:32 wiz Exp $

BUILDLINK_TREE+=	kf6-kservice

.if !defined(KF6_KSERVICE_BUILDLINK3_MK)
KF6_KSERVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kservice+=	kf6-kservice>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kservice?=	kf6-kservice>=6.26.0nb1
BUILDLINK_PKGSRCDIR.kf6-kservice?=	../../devel/kf6-kservice

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KSERVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kservice
