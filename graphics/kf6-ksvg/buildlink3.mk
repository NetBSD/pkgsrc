# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:24:52 markd Exp $

BUILDLINK_TREE+=	kf6-ksvg

.if !defined(KF6_KSVG_BUILDLINK3_MK)
KF6_KSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-ksvg+=	kf6-ksvg>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-ksvg?=		../../graphics/kf6-ksvg

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-ksvg
