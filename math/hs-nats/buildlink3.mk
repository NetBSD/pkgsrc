# $NetBSD: buildlink3.mk,v 1.1 2014/05/28 22:01:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-nats

.if !defined(HS_NATS_BUILDLINK3_MK)
HS_NATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-nats+=	hs-nats>=0.1.3
BUILDLINK_PKGSRCDIR.hs-nats?=	../../math/hs-nats
.endif	# HS_NATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-nats
