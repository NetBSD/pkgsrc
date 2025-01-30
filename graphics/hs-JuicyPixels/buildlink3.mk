# $NetBSD: buildlink3.mk,v 1.13 2025/01/30 09:50:50 pho Exp $

BUILDLINK_TREE+=	hs-JuicyPixels

.if !defined(HS_JUICYPIXELS_BUILDLINK3_MK)
HS_JUICYPIXELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.9
BUILDLINK_ABI_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.9
BUILDLINK_PKGSRCDIR.hs-JuicyPixels?=	../../graphics/hs-JuicyPixels

.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_JUICYPIXELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-JuicyPixels
