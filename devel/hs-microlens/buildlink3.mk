# $NetBSD: buildlink3.mk,v 1.7 2023/11/02 06:36:46 pho Exp $

BUILDLINK_TREE+=	hs-microlens

.if !defined(HS_MICROLENS_BUILDLINK3_MK)
HS_MICROLENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microlens+=	hs-microlens>=0.4.13
BUILDLINK_ABI_DEPENDS.hs-microlens+=	hs-microlens>=0.4.13.1nb3
BUILDLINK_PKGSRCDIR.hs-microlens?=	../../devel/hs-microlens
.endif	# HS_MICROLENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microlens
