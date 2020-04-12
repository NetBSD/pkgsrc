# $NetBSD: buildlink3.mk,v 1.18 2020/04/12 08:27:52 adam Exp $

BUILDLINK_TREE+=	kidletime

.if !defined(KIDLETIME_BUILDLINK3_MK)
KIDLETIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kidletime+=	kidletime>=5.18.0
BUILDLINK_ABI_DEPENDS.kidletime?=	kidletime>=5.66.0nb3
BUILDLINK_PKGSRCDIR.kidletime?=		../../devel/kidletime

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# KIDLETIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kidletime
