# $NetBSD: buildlink3.mk,v 1.3 2017/02/06 13:54:39 wiz Exp $

BUILDLINK_TREE+=	kpeople

.if !defined(KPEOPLE_BUILDLINK3_MK)
KPEOPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpeople+=	kpeople>=5.19.0
BUILDLINK_ABI_DEPENDS.kpeople?=	kpeople>=5.25.0nb2
BUILDLINK_PKGSRCDIR.kpeople?=	../../devel/kpeople

.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# KPEOPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpeople
