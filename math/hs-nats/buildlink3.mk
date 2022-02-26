# $NetBSD: buildlink3.mk,v 1.15 2022/02/26 03:58:18 pho Exp $

BUILDLINK_TREE+=	hs-nats

.if !defined(HS_NATS_BUILDLINK3_MK)
HS_NATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-nats+=	hs-nats>=1.1.2
BUILDLINK_ABI_DEPENDS.hs-nats+=	hs-nats>=1.1.2nb4
BUILDLINK_PKGSRCDIR.hs-nats?=	../../math/hs-nats

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_NATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-nats
