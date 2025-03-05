# $NetBSD: buildlink3.mk,v 1.10 2025/03/05 03:39:23 pho Exp $

BUILDLINK_TREE+=	hs-ordered-containers

.if !defined(HS_ORDERED_CONTAINERS_BUILDLINK3_MK)
HS_ORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ordered-containers+=	hs-ordered-containers>=0.2.4
BUILDLINK_ABI_DEPENDS.hs-ordered-containers+=	hs-ordered-containers>=0.2.4nb2
BUILDLINK_PKGSRCDIR.hs-ordered-containers?=	../../devel/hs-ordered-containers

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_ORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ordered-containers
