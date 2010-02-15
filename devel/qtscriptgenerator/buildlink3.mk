# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/15 15:57:49 wiz Exp $

BUILDLINK_TREE+=	qtscriptgenerator

.if !defined(QTSCRIPTGENERATOR_BUILDLINK3_MK)
QTSCRIPTGENERATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtscriptgenerator+=	qtscriptgenerator>=0.1.0
BUILDLINK_ABI_DEPENDS.qtscriptgenerator?=	qtscriptgenerator>=0.1.0nb2
BUILDLINK_PKGSRCDIR.qtscriptgenerator?=	../../devel/qtscriptgenerator

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QTSCRIPTGENERATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtscriptgenerator
