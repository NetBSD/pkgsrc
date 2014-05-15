# $NetBSD: buildlink3.mk,v 1.1 2014/05/15 21:15:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-transformers

.if !defined(HS_TRANSFORMERS_BUILDLINK3_MK)
HS_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers+=	hs-transformers>=0.4.1
BUILDLINK_PKGSRCDIR.hs-transformers?=	../../devel/hs-transformers
.endif	# HS_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers
