# $NetBSD: buildlink3.mk,v 1.9 2026/11/13 14:39:09 pho Exp $

BUILDLINK_TREE+=	hs-newtype-generics

.if !defined(HS_NEWTYPE_GENERICS_BUILDLINK3_MK)
HS_NEWTYPE_GENERICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-newtype-generics+=	hs-newtype-generics>=0.6.2
BUILDLINK_ABI_DEPENDS.hs-newtype-generics+=	hs-newtype-generics>=0.6.2nb8
BUILDLINK_PKGSRCDIR.hs-newtype-generics?=	../../devel/hs-newtype-generics
.endif	# HS_NEWTYPE_GENERICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-newtype-generics
