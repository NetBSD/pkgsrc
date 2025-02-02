# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:38 pho Exp $

BUILDLINK_TREE+=	hs-quote-quot

.if !defined(HS_QUOTE_QUOT_BUILDLINK3_MK)
HS_QUOTE_QUOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-quote-quot+=	hs-quote-quot>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-quote-quot+=	hs-quote-quot>=0.2.1.0nb3
BUILDLINK_PKGSRCDIR.hs-quote-quot?=	../../math/hs-quote-quot
.endif	# HS_QUOTE_QUOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-quote-quot
