# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:19:29 pho Exp $

BUILDLINK_TREE+=	hs-bytesmith

.if !defined(HS_BYTESMITH_BUILDLINK3_MK)
HS_BYTESMITH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bytesmith+=	hs-bytesmith>=0.3.11
BUILDLINK_ABI_DEPENDS.hs-bytesmith+=	hs-bytesmith>=0.3.11.1
BUILDLINK_PKGSRCDIR.hs-bytesmith?=	../../devel/hs-bytesmith

.include "../../devel/hs-byteslice/buildlink3.mk"
.include "../../devel/hs-contiguous/buildlink3.mk"
.include "../../math/hs-natural-arithmetic/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-wide-word/buildlink3.mk"
.endif	# HS_BYTESMITH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bytesmith
