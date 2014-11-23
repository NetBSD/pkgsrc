# $NetBSD: buildlink3.mk,v 1.3 2014/11/23 12:51:34 szptvlfn Exp $

BUILDLINK_TREE+=	hs-transformers

.if !defined(HS_TRANSFORMERS_BUILDLINK3_MK)
HS_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers+=	hs-transformers>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-transformers+=	hs-transformers>=0.4.2.0
BUILDLINK_PKGSRCDIR.hs-transformers?=	../../devel/hs-transformers
.endif	# HS_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers
