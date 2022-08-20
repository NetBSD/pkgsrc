# $NetBSD: buildlink3.mk,v 1.8 2022/08/20 08:08:20 wiz Exp $

BUILDLINK_TREE+=	hs-JuicyPixels

.if !defined(HS_JUICYPIXELS_BUILDLINK3_MK)
HS_JUICYPIXELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.6
BUILDLINK_ABI_DEPENDS.hs-JuicyPixels+=	hs-JuicyPixels>=3.3.6nb3
BUILDLINK_PKGSRCDIR.hs-JuicyPixels?=	../../graphics/hs-JuicyPixels

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_JUICYPIXELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-JuicyPixels
