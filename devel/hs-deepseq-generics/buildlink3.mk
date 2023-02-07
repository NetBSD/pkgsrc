# $NetBSD: buildlink3.mk,v 1.8 2023/02/07 01:40:32 pho Exp $

BUILDLINK_TREE+=	hs-deepseq-generics

.if !defined(HS_DEEPSEQ_GENERICS_BUILDLINK3_MK)
HS_DEEPSEQ_GENERICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deepseq-generics+=	hs-deepseq-generics>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-deepseq-generics+=	hs-deepseq-generics>=0.2.0.0nb5
BUILDLINK_PKGSRCDIR.hs-deepseq-generics?=	../../devel/hs-deepseq-generics
.endif	# HS_DEEPSEQ_GENERICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deepseq-generics
