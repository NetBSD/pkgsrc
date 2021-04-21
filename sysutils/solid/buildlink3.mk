# $NetBSD: buildlink3.mk,v 1.21 2021/04/21 11:40:39 adam Exp $

BUILDLINK_TREE+=	solid

.if !defined(SOLID_BUILDLINK3_MK)
SOLID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.solid+=	solid>=5.18.0
BUILDLINK_ABI_DEPENDS.solid?=	solid>=5.80.0nb1
BUILDLINK_PKGSRCDIR.solid?=	../../sysutils/solid

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# SOLID_BUILDLINK3_MK

BUILDLINK_TREE+=	-solid
