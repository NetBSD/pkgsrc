# $NetBSD: buildlink3.mk,v 1.7 2011/11/01 06:01:03 sbd Exp $

BUILDLINK_TREE+=	qtscriptgenerator

.if !defined(QTSCRIPTGENERATOR_BUILDLINK3_MK)
QTSCRIPTGENERATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qtscriptgenerator+=	qtscriptgenerator>=0.1.0
BUILDLINK_ABI_DEPENDS.qtscriptgenerator?=	qtscriptgenerator>=0.1.0nb11
BUILDLINK_PKGSRCDIR.qtscriptgenerator?=	../../devel/qtscriptgenerator

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QTSCRIPTGENERATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-qtscriptgenerator
