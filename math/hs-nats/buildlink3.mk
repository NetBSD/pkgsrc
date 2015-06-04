# $NetBSD: buildlink3.mk,v 1.7 2015/06/04 20:08:59 szptvlfn Exp $

BUILDLINK_TREE+=	hs-nats

.if !defined(HS_NATS_BUILDLINK3_MK)
HS_NATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-nats+=	hs-nats>=0.2
BUILDLINK_ABI_DEPENDS.hs-nats+=	hs-nats>=0.2nb5
BUILDLINK_PKGSRCDIR.hs-nats?=	../../math/hs-nats

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_NATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-nats
