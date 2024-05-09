# $NetBSD: buildlink3.mk,v 1.23 2024/05/09 01:32:18 pho Exp $

BUILDLINK_TREE+=	hs-unordered-containers

.if !defined(HS_UNORDERED_CONTAINERS_BUILDLINK3_MK)
HS_UNORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.20
BUILDLINK_ABI_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.20nb1
BUILDLINK_PKGSRCDIR.hs-unordered-containers?=	../../devel/hs-unordered-containers

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_UNORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unordered-containers
