# $NetBSD: buildlink3.mk,v 1.13 2024/05/09 01:31:57 pho Exp $

BUILDLINK_TREE+=	hs-hashtables

.if !defined(HS_HASHTABLES_BUILDLINK3_MK)
HS_HASHTABLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashtables+=	hs-hashtables>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-hashtables+=	hs-hashtables>=1.3.1nb4
BUILDLINK_PKGSRCDIR.hs-hashtables?=	../../devel/hs-hashtables

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_HASHTABLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashtables
