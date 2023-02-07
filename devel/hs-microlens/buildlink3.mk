# $NetBSD: buildlink3.mk,v 1.5 2023/02/07 01:40:43 pho Exp $

BUILDLINK_TREE+=	hs-microlens

.if !defined(HS_MICROLENS_BUILDLINK3_MK)
HS_MICROLENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microlens+=	hs-microlens>=0.4.13
BUILDLINK_ABI_DEPENDS.hs-microlens+=	hs-microlens>=0.4.13.1nb1
BUILDLINK_PKGSRCDIR.hs-microlens?=	../../devel/hs-microlens
.endif	# HS_MICROLENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microlens
