# $NetBSD: buildlink3.mk,v 1.10 2025/02/02 13:05:00 pho Exp $

BUILDLINK_TREE+=	hs-cborg

.if !defined(HS_CBORG_BUILDLINK3_MK)
HS_CBORG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cborg+=	hs-cborg>=0.2.10
BUILDLINK_ABI_DEPENDS.hs-cborg+=	hs-cborg>=0.2.10.0nb2
BUILDLINK_PKGSRCDIR.hs-cborg?=		../../devel/hs-cborg

.include "../../devel/hs-half/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_CBORG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cborg
