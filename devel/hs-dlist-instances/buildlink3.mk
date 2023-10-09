# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 04:54:12 pho Exp $

BUILDLINK_TREE+=	hs-dlist-instances

.if !defined(HS_DLIST_INSTANCES_BUILDLINK3_MK)
HS_DLIST_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist-instances+=	hs-dlist-instances>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-dlist-instances+=	hs-dlist-instances>=0.1.1.1nb3
BUILDLINK_PKGSRCDIR.hs-dlist-instances?=	../../devel/hs-dlist-instances

.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_DLIST_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist-instances
