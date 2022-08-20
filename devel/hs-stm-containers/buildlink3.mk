# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:18 wiz Exp $

BUILDLINK_TREE+=	hs-stm-containers

.if !defined(HS_STM_CONTAINERS_BUILDLINK3_MK)
HS_STM_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm-containers+=	hs-stm-containers>=1.2
BUILDLINK_ABI_DEPENDS.hs-stm-containers+=	hs-stm-containers>=1.2nb2
BUILDLINK_PKGSRCDIR.hs-stm-containers?=		../../devel/hs-stm-containers

.include "../../devel/hs-deferred-folds/buildlink3.mk"
.include "../../devel/hs-focus/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-list-t/buildlink3.mk"
.include "../../devel/hs-stm-hamt/buildlink3.mk"
.endif	# HS_STM_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm-containers
