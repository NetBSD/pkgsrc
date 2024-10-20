# $NetBSD: buildlink3.mk,v 1.3 2024/10/20 14:04:33 wiz Exp $

BUILDLINK_TREE+=	kf6-baloo

.if !defined(KF6_BALOO_BUILDLINK3_MK)
KF6_BALOO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-baloo+=	kf6-baloo>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-baloo?=		kf6-baloo>=6.2.0nb3
BUILDLINK_PKGSRCDIR.kf6-baloo?=		../../sysutils/kf6-baloo

#.include "../../devel/libinotify/buildlink3.mk"
.include "../../databases/lmdb/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../sysutils/kf6-kfilemetadata/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_BALOO_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-baloo
