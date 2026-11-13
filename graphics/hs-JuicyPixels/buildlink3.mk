# $NetBSD: buildlink3.mk,v 1.17 2026/11/13 14:39:28 pho Exp $

BUILDLINK_TREE+=	hs-JuicyPixels

.if !defined(HS_JUICYPIXELS_BUILDLINK3_MK)
HS_JUICYPIXELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.9
BUILDLINK_ABI_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.9nb4
BUILDLINK_PKGSRCDIR.hs-JuicyPixels?=	../../graphics/hs-JuicyPixels

.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_JUICYPIXELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-JuicyPixels
