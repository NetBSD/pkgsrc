# $NetBSD: buildlink3.mk,v 1.22 2021/12/08 16:02:40 adam Exp $

BUILDLINK_TREE+=	solid

.if !defined(SOLID_BUILDLINK3_MK)
SOLID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.solid+=	solid>=5.18.0
BUILDLINK_ABI_DEPENDS.solid?=	solid>=5.80.0nb3
BUILDLINK_PKGSRCDIR.solid?=	../../sysutils/solid

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# SOLID_BUILDLINK3_MK

BUILDLINK_TREE+=	-solid
