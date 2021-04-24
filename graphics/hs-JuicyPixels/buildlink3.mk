# $NetBSD: buildlink3.mk,v 1.2 2021/04/24 12:12:01 pho Exp $

BUILDLINK_TREE+=	hs-JuicyPixels

.if !defined(HS_JUICYPIXELS_BUILDLINK3_MK)
HS_JUICYPIXELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.5
BUILDLINK_ABI_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.5
BUILDLINK_PKGSRCDIR.hs-JuicyPixels?=	../../graphics/hs-JuicyPixels

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_JUICYPIXELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-JuicyPixels
