# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 16:34:02 pho Exp $

BUILDLINK_TREE+=	hs-byteslice

.if !defined(HS_BYTESLICE_BUILDLINK3_MK)
HS_BYTESLICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-byteslice+=	hs-byteslice>=0.2.14
BUILDLINK_ABI_DEPENDS.hs-byteslice+=	hs-byteslice>=0.2.14.0
BUILDLINK_PKGSRCDIR.hs-byteslice?=	../../devel/hs-byteslice

.include "../../math/hs-natural-arithmetic/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-primitive-addr/buildlink3.mk"
.include "../../devel/hs-primitive-unlifted/buildlink3.mk"
.include "../../devel/hs-run-st/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-tuples/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_BYTESLICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-byteslice
