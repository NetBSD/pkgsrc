# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:18:42 markd Exp $

BUILDLINK_TREE+=	kf6-kiconthemes

.if !defined(KF6_KICONTHEMES_BUILDLINK3_MK)
KF6_KICONTHEMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kiconthemes+=	kf6-kiconthemes>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kiconthemes?=	../../graphics/kf6-kiconthemes

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kitemviews/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KICONTHEMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kiconthemes
