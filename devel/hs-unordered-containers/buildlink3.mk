# $NetBSD: buildlink3.mk,v 1.7 2015/06/04 20:08:59 szptvlfn Exp $

BUILDLINK_TREE+=	hs-unordered-containers

.if !defined(HS_UNORDERED_CONTAINERS_BUILDLINK3_MK)
HS_UNORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.5
BUILDLINK_ABI_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.5.0nb5
BUILDLINK_PKGSRCDIR.hs-unordered-containers?=	../../devel/hs-unordered-containers

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_UNORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unordered-containers
