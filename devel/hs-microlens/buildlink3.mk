# $NetBSD: buildlink3.mk,v 1.4 2023/01/24 16:08:25 pho Exp $

BUILDLINK_TREE+=	hs-microlens

.if !defined(HS_MICROLENS_BUILDLINK3_MK)
HS_MICROLENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microlens+=	hs-microlens>=0.4.13
BUILDLINK_ABI_DEPENDS.hs-microlens+=	hs-microlens>=0.4.13.1
BUILDLINK_PKGSRCDIR.hs-microlens?=	../../devel/hs-microlens
.endif	# HS_MICROLENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microlens
