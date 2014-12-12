# $NetBSD: buildlink3.mk,v 1.6 2014/12/12 22:55:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-nats

.if !defined(HS_NATS_BUILDLINK3_MK)
HS_NATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-nats+=	hs-nats>=0.2
BUILDLINK_ABI_DEPENDS.hs-nats+=	hs-nats>=0.2nb4
BUILDLINK_PKGSRCDIR.hs-nats?=	../../math/hs-nats

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_NATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-nats
