# $NetBSD: buildlink3.mk,v 1.6 2023/02/07 01:40:50 pho Exp $

BUILDLINK_TREE+=	hs-storable-record

.if !defined(HS_STORABLE_RECORD_BUILDLINK3_MK)
HS_STORABLE_RECORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-storable-record+=	hs-storable-record>=0.0.6
BUILDLINK_ABI_DEPENDS.hs-storable-record+=	hs-storable-record>=0.0.6nb3
BUILDLINK_PKGSRCDIR.hs-storable-record?=	../../devel/hs-storable-record

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.endif	# HS_STORABLE_RECORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-storable-record
