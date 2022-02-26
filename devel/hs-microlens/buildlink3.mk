# $NetBSD: buildlink3.mk,v 1.3 2022/02/26 03:58:01 pho Exp $

BUILDLINK_TREE+=	hs-microlens

.if !defined(HS_MICROLENS_BUILDLINK3_MK)
HS_MICROLENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microlens+=	hs-microlens>=0.4.12
BUILDLINK_ABI_DEPENDS.hs-microlens+=	hs-microlens>=0.4.12.0nb2
BUILDLINK_PKGSRCDIR.hs-microlens?=	../../devel/hs-microlens
.endif	# HS_MICROLENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microlens
