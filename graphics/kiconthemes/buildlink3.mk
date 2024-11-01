# $NetBSD: buildlink3.mk,v 1.35 2024/11/01 00:52:10 wiz Exp $

BUILDLINK_TREE+=	kiconthemes

.if !defined(KICONTHEMES_BUILDLINK3_MK)
KICONTHEMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kiconthemes+=	kiconthemes>=5.19.0
BUILDLINK_ABI_DEPENDS.kiconthemes?=	kiconthemes>=5.116.0nb1
BUILDLINK_PKGSRCDIR.kiconthemes?=	../../graphics/kiconthemes

.include "../../x11/kconfigwidgets/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif	# KICONTHEMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-kiconthemes
