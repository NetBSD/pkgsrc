# $NetBSD: buildlink3.mk,v 1.14 2010/12/23 11:44:40 dsainty Exp $

BUILDLINK_TREE+=	jasper

.if !defined(JASPER_BUILDLINK3_MK)
JASPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jasper+=	jasper>=1.600.0
BUILDLINK_ABI_DEPENDS.jasper+=	jasper>=1.900.1nb5
BUILDLINK_PKGSRCDIR.jasper?=	../../graphics/jasper

.include "../../mk/jpeg.buildlink3.mk"
.endif # JASPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-jasper
