# $NetBSD: buildlink3.mk,v 1.10 2011/08/07 20:36:20 wiz Exp $

BUILDLINK_TREE+=	camlimages

.if !defined(CAMLIMAGES_BUILDLINK3_MK)
CAMLIMAGES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.camlimages+=	camlimages>=4.0.1
BUILDLINK_ABI_DEPENDS.camlimages?=	camlimages>=4.0.1
BUILDLINK_PKGSRCDIR.camlimages?=	../../graphics/camlimages
.endif # CAMLIMAGES_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlimages
