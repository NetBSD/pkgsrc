# $NetBSD: buildlink3.mk,v 1.6 2023/11/02 06:36:50 pho Exp $

BUILDLINK_TREE+=	hs-ordered-containers

.if !defined(HS_ORDERED_CONTAINERS_BUILDLINK3_MK)
HS_ORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ordered-containers+=	hs-ordered-containers>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-ordered-containers+=	hs-ordered-containers>=0.2.3nb3
BUILDLINK_PKGSRCDIR.hs-ordered-containers?=	../../devel/hs-ordered-containers
.endif	# HS_ORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ordered-containers
