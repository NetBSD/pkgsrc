# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:37 joerg Exp $

BUILDLINK_TREE+=	camlimages

.if !defined(CAMLIMAGES_BUILDLINK3_MK)
CAMLIMAGES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.camlimages+=	camlimages>=2.2.0
BUILDLINK_ABI_DEPENDS.camlimages?=	camlimages>=2.2.0nb1
BUILDLINK_PKGSRCDIR.camlimages?=	../../graphics/camlimages
.endif # CAMLIMAGES_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlimages
