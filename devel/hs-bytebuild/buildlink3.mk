# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:10:02 pho Exp $

BUILDLINK_TREE+=	hs-bytebuild

.if !defined(HS_BYTEBUILD_BUILDLINK3_MK)
HS_BYTEBUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytebuild+=	hs-bytebuild>=0.3.16
BUILDLINK_ABI_DEPENDS.hs-bytebuild+=	hs-bytebuild>=0.3.16.3
BUILDLINK_PKGSRCDIR.hs-bytebuild?=	../../devel/hs-bytebuild

.include "../../devel/hs-byteslice/buildlink3.mk"
.include "../../devel/hs-haskell-src-meta/buildlink3.mk"
.include "../../math/hs-integer-logarithms/buildlink3.mk"
.include "../../math/hs-natural-arithmetic/buildlink3.mk"
.include "../../devel/hs-primitive-offset/buildlink3.mk"
.include "../../devel/hs-run-st/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-wide-word/buildlink3.mk"
.include "../../devel/hs-zigzag/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_BYTEBUILD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytebuild
