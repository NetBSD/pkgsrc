# $NetBSD: buildlink3.mk,v 1.15 2022/01/18 02:48:15 pho Exp $

BUILDLINK_TREE+=	hs-unordered-containers

.if !defined(HS_UNORDERED_CONTAINERS_BUILDLINK3_MK)
HS_UNORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.13
BUILDLINK_ABI_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.13.0nb2
BUILDLINK_PKGSRCDIR.hs-unordered-containers?=	../../devel/hs-unordered-containers

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_UNORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unordered-containers
