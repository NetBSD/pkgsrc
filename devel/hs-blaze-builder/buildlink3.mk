# $NetBSD: buildlink3.mk,v 1.4 2014/12/12 22:04:21 szptvlfn Exp $

BUILDLINK_TREE+=	hs-blaze-builder

.if !defined(HS_BLAZE_BUILDER_BUILDLINK3_MK)
HS_BLAZE_BUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-blaze-builder+=	hs-blaze-builder>=0.3.3.3nb1
BUILDLINK_PKGSRCDIR.hs-blaze-builder?=	../../devel/hs-blaze-builder

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_BLAZE_BUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder
