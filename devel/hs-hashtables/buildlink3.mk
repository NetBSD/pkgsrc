# $NetBSD: buildlink3.mk,v 1.16 2025/03/05 03:39:14 pho Exp $

BUILDLINK_TREE+=	hs-hashtables

.if !defined(HS_HASHTABLES_BUILDLINK3_MK)
HS_HASHTABLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashtables+=	hs-hashtables>=1.4.2
BUILDLINK_ABI_DEPENDS.hs-hashtables+=	hs-hashtables>=1.4.2nb2
BUILDLINK_PKGSRCDIR.hs-hashtables?=	../../devel/hs-hashtables

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_HASHTABLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashtables
