# $NetBSD: buildlink3.mk,v 1.30 2021/04/21 11:40:18 adam Exp $

BUILDLINK_TREE+=	kitemmodels

.if !defined(KITEMMODELS_BUILDLINK3_MK)
KITEMMODELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kitemmodels+=	kitemmodels>=5.18.0
BUILDLINK_ABI_DEPENDS.kitemmodels?=	kitemmodels>=5.80.0nb1
BUILDLINK_PKGSRCDIR.kitemmodels?=	../../devel/kitemmodels

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# KITEMMODELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kitemmodels
