# $NetBSD: buildlink3.mk,v 1.13 2022/05/24 18:59:33 jaapb Exp $

BUILDLINK_TREE+=	camlimages

.if !defined(CAMLIMAGES_BUILDLINK3_MK)
CAMLIMAGES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.camlimages+=	camlimages>=4.0.1
BUILDLINK_ABI_DEPENDS.camlimages+=	camlimages>=4.0.1nb98
BUILDLINK_PKGSRCDIR.camlimages?=	../../graphics/camlimages
.endif # CAMLIMAGES_BUILDLINK3_MK

BUILDLINK_TREE+=	-camlimages
