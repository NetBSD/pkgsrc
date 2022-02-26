# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:58:08 pho Exp $

BUILDLINK_TREE+=	hs-storable-record

.if !defined(HS_STORABLE_RECORD_BUILDLINK3_MK)
HS_STORABLE_RECORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-storable-record+=	hs-storable-record>=0.0.6
BUILDLINK_ABI_DEPENDS.hs-storable-record+=	hs-storable-record>=0.0.6nb2
BUILDLINK_PKGSRCDIR.hs-storable-record?=	../../devel/hs-storable-record

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.endif	# HS_STORABLE_RECORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-storable-record
