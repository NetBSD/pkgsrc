# $NetBSD: buildlink3.mk,v 1.16 2026/01/07 08:49:04 wiz Exp $

BUILDLINK_TREE+=	ktextaddons

.if !defined(KTEXTADDONS_BUILDLINK3_MK)
KTEXTADDONS_BUILDLINK3_MK:=


BUILDLINK_API_DEPENDS.ktextaddons+=	ktextaddons>=1.8.0
BUILDLINK_ABI_DEPENDS.ktextaddons?=	ktextaddons>=1.8.0nb1
BUILDLINK_PKGSRCDIR.ktextaddons?=	../../textproc/ktextaddons

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../textproc/kf6-syntax-highlighting/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KTEXTADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktextaddons
