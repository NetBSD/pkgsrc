# $NetBSD: buildlink3.mk,v 1.3 2023/01/25 16:27:12 pho Exp $

BUILDLINK_TREE+=	hs-cborg

.if !defined(HS_CBORG_BUILDLINK3_MK)
HS_CBORG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cborg+=	hs-cborg>=0.2.8
BUILDLINK_ABI_DEPENDS.hs-cborg+=	hs-cborg>=0.2.8.0
BUILDLINK_PKGSRCDIR.hs-cborg?=		../../devel/hs-cborg

.include "../../devel/hs-half/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_CBORG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cborg
