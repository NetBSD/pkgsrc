# $NetBSD: buildlink3.mk,v 1.21 2025/03/05 03:39:43 pho Exp $

BUILDLINK_TREE+=	hs-nats

.if !defined(HS_NATS_BUILDLINK3_MK)
HS_NATS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-nats+=	hs-nats>=1.1.2
BUILDLINK_ABI_DEPENDS.hs-nats+=	hs-nats>=1.1.2nb10
BUILDLINK_PKGSRCDIR.hs-nats?=	../../math/hs-nats

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_NATS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-nats
