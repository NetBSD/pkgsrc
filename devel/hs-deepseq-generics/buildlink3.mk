# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:08:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-deepseq-generics

.if !defined(HS_DEEPSEQ_GENERICS_BUILDLINK3_MK)
HS_DEEPSEQ_GENERICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deepseq-generics+=	hs-deepseq-generics>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-deepseq-generics+=	hs-deepseq-generics>=0.1.1.1
BUILDLINK_PKGSRCDIR.hs-deepseq-generics?=	../../devel/hs-deepseq-generics
.endif	# HS_DEEPSEQ_GENERICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deepseq-generics
