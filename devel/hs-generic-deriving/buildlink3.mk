# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:08 pho Exp $

BUILDLINK_TREE+=	hs-generic-deriving

.if !defined(HS_GENERIC_DERIVING_BUILDLINK3_MK)
HS_GENERIC_DERIVING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-deriving+=	hs-generic-deriving>=1.14
BUILDLINK_ABI_DEPENDS.hs-generic-deriving+=	hs-generic-deriving>=1.14nb2
BUILDLINK_PKGSRCDIR.hs-generic-deriving?=	../../devel/hs-generic-deriving

.include "../../devel/hs-th-abstraction/buildlink3.mk"
.endif	# HS_GENERIC_DERIVING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-deriving
