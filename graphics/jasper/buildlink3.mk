# $NetBSD: buildlink3.mk,v 1.12 2009/08/26 19:56:38 sno Exp $

BUILDLINK_TREE+=	jasper

.if !defined(JASPER_BUILDLINK3_MK)
JASPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jasper+=	jasper>=1.600.0
BUILDLINK_ABI_DEPENDS.jasper+=	jasper>=1.900.1nb3
BUILDLINK_PKGSRCDIR.jasper?=	../../graphics/jasper

.include "../../graphics/jpeg/buildlink3.mk"
.endif # JASPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-jasper
