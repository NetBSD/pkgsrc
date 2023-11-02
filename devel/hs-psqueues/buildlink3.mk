# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:36:52 pho Exp $

BUILDLINK_TREE+=	hs-psqueues

.if !defined(HS_PSQUEUES_BUILDLINK3_MK)
HS_PSQUEUES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-psqueues+=	hs-psqueues>=0.2.7
BUILDLINK_ABI_DEPENDS.hs-psqueues+=	hs-psqueues>=0.2.7.3nb5
BUILDLINK_PKGSRCDIR.hs-psqueues?=	../../devel/hs-psqueues

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_PSQUEUES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-psqueues
