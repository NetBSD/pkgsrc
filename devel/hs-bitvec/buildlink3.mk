# $NetBSD: buildlink3.mk,v 1.4 2023/10/29 10:07:00 pho Exp $

BUILDLINK_TREE+=	hs-bitvec

.if !defined(HS_BITVEC_BUILDLINK3_MK)
HS_BITVEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bitvec+=	hs-bitvec>=1.1.5.0
BUILDLINK_ABI_DEPENDS.hs-bitvec?=	hs-bitvec>=1.1.5.0
BUILDLINK_PKGSRCDIR.hs-bitvec?=		../../devel/hs-bitvec

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_BITVEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bitvec
