# $NetBSD: buildlink3.mk,v 1.1 2020/01/16 15:51:15 pho Exp $

BUILDLINK_TREE+=	hs-JuicyPixels

.if !defined(HS_JUICYPIXELS_BUILDLINK3_MK)
HS_JUICYPIXELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.4
BUILDLINK_ABI_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.4
BUILDLINK_PKGSRCDIR.hs-JuicyPixels?=	../../graphics/hs-JuicyPixels

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_JUICYPIXELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-JuicyPixels
