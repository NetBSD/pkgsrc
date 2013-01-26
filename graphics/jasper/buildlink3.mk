# $NetBSD: buildlink3.mk,v 1.15 2013/01/26 21:36:28 adam Exp $

BUILDLINK_TREE+=	jasper

.if !defined(JASPER_BUILDLINK3_MK)
JASPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jasper+=	jasper>=1.600.0
BUILDLINK_ABI_DEPENDS.jasper+=	jasper>=1.900.1nb7
BUILDLINK_PKGSRCDIR.jasper?=	../../graphics/jasper

.include "../../mk/jpeg.buildlink3.mk"
.endif # JASPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-jasper
