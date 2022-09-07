# $NetBSD: buildlink3.mk,v 1.1 2022/09/07 02:56:00 pho Exp $

BUILDLINK_TREE+=	hs-newtype

.if !defined(HS_NEWTYPE_BUILDLINK3_MK)
HS_NEWTYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-newtype+=	hs-newtype>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-newtype+=	hs-newtype>=0.2.2.0
BUILDLINK_PKGSRCDIR.hs-newtype?=	../../devel/hs-newtype
.endif	# HS_NEWTYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-newtype
