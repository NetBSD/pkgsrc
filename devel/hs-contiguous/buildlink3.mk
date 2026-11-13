# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:38:53 pho Exp $

BUILDLINK_TREE+=	hs-contiguous

.if !defined(HS_CONTIGUOUS_BUILDLINK3_MK)
HS_CONTIGUOUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contiguous+=	hs-contiguous>=0.6.4
BUILDLINK_ABI_DEPENDS.hs-contiguous+=	hs-contiguous>=0.6.4.2nb2
BUILDLINK_PKGSRCDIR.hs-contiguous?=	../../devel/hs-contiguous

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-primitive-unlifted/buildlink3.mk"
.include "../../devel/hs-run-st/buildlink3.mk"
.endif	# HS_CONTIGUOUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contiguous
