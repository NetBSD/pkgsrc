# $NetBSD: buildlink3.mk,v 1.4 2019/12/31 14:36:26 pho Exp $

BUILDLINK_TREE+=	hs-transformers

.if !defined(HS_TRANSFORMERS_BUILDLINK3_MK)
HS_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers+=	hs-transformers>=0.5.6
BUILDLINK_ABI_DEPENDS.hs-transformers+=	hs-transformers>=0.5.6.2
BUILDLINK_PKGSRCDIR.hs-transformers?=	../../devel/hs-transformers
.endif	# HS_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers
