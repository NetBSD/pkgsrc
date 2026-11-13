# $NetBSD: buildlink3.mk,v 1.9 2026/11/13 14:39:09 pho Exp $

BUILDLINK_TREE+=	hs-newtype

.if !defined(HS_NEWTYPE_BUILDLINK3_MK)
HS_NEWTYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-newtype+=	hs-newtype>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-newtype+=	hs-newtype>=0.2.2.0nb8
BUILDLINK_PKGSRCDIR.hs-newtype?=	../../devel/hs-newtype
.endif	# HS_NEWTYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-newtype
