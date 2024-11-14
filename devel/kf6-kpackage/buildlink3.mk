# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:19:26 wiz Exp $

BUILDLINK_TREE+=	kf6-kpackage

.if !defined(KF6_KPACKAGE_BUILDLINK3_MK)
KF6_KPACKAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kpackage+=	kf6-kpackage>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kpackage?=	kf6-kpackage>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kpackage?=	../../devel/kf6-kpackage

BUILDLINK_FILES.kf6-kpackage+=		bin/kpackagetool6

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KPACKAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kpackage
