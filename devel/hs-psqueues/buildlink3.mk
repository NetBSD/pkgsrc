# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:11 pho Exp $

BUILDLINK_TREE+=	hs-psqueues

.if !defined(HS_PSQUEUES_BUILDLINK3_MK)
HS_PSQUEUES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-psqueues+=	hs-psqueues>=0.2.7
BUILDLINK_ABI_DEPENDS.hs-psqueues+=	hs-psqueues>=0.2.7.2nb1
BUILDLINK_PKGSRCDIR.hs-psqueues?=	../../devel/hs-psqueues

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_PSQUEUES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-psqueues
