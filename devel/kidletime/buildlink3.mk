# $NetBSD: buildlink3.mk,v 1.15 2020/01/18 21:48:04 jperkin Exp $

BUILDLINK_TREE+=	kidletime

.if !defined(KIDLETIME_BUILDLINK3_MK)
KIDLETIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kidletime+=	kidletime>=5.18.0
BUILDLINK_ABI_DEPENDS.kidletime?=	kidletime>=5.64.0nb1
BUILDLINK_PKGSRCDIR.kidletime?=		../../devel/kidletime

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KIDLETIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kidletime
