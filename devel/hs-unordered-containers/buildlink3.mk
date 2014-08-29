# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:08:40 szptvlfn Exp $

BUILDLINK_TREE+=	hs-unordered-containers

.if !defined(HS_UNORDERED_CONTAINERS_BUILDLINK3_MK)
HS_UNORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.5
BUILDLINK_ABI_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.5.0
BUILDLINK_PKGSRCDIR.hs-unordered-containers?=	../../devel/hs-unordered-containers

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_UNORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unordered-containers
