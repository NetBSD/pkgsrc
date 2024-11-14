# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:19:25 wiz Exp $

BUILDLINK_TREE+=	kf6-kcolorscheme

.if !defined(KF6_KCOLORSCHEME_BUILDLINK3_MK)
KF6_KCOLORSCHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kcolorscheme+=	kf6-kcolorscheme>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kcolorscheme?=		kf6-kcolorscheme>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-kcolorscheme?=		../../devel/kf6-kcolorscheme

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KCOLORSCHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kcolorscheme
