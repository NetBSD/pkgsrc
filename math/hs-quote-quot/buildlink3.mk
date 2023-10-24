# $NetBSD: buildlink3.mk,v 1.1 2023/10/24 08:35:10 pho Exp $

BUILDLINK_TREE+=	hs-quote-quot

.if !defined(HS_QUOTE_QUOT_BUILDLINK3_MK)
HS_QUOTE_QUOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-quote-quot+=	hs-quote-quot>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-quote-quot+=	hs-quote-quot>=0.2.1.0
BUILDLINK_PKGSRCDIR.hs-quote-quot?=	../../math/hs-quote-quot
.endif	# HS_QUOTE_QUOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-quote-quot
