# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:22 pho Exp $

BUILDLINK_TREE+=	hs-tuple

.if !defined(HS_TUPLE_BUILDLINK3_MK)
HS_TUPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tuple+=	hs-tuple>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-tuple+=	hs-tuple>=0.3.0.2nb2
BUILDLINK_PKGSRCDIR.hs-tuple?=		../../devel/hs-tuple

.include "../../devel/hs-OneTuple/buildlink3.mk"
.endif	# HS_TUPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tuple
