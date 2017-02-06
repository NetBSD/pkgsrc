# $NetBSD: buildlink3.mk,v 1.5 2017/02/06 13:54:39 wiz Exp $

BUILDLINK_TREE+=	kitemmodels

.if !defined(KITEMMODELS_BUILDLINK3_MK)
KITEMMODELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kitemmodels+=	kitemmodels>=5.18.0
BUILDLINK_ABI_DEPENDS.kitemmodels?=	kitemmodels>=5.25.0nb3
BUILDLINK_PKGSRCDIR.kitemmodels?=	../../devel/kitemmodels

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# KITEMMODELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kitemmodels
