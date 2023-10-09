# $NetBSD: buildlink3.mk,v 1.10 2023/10/09 04:54:39 pho Exp $

BUILDLINK_TREE+=	hs-contravariant

.if !defined(HS_CONTRAVARIANT_BUILDLINK3_MK)
HS_CONTRAVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contravariant+=	hs-contravariant>=1.5.5
BUILDLINK_ABI_DEPENDS.hs-contravariant+=	hs-contravariant>=1.5.5nb4
BUILDLINK_PKGSRCDIR.hs-contravariant?=		../../math/hs-contravariant

.include "../../devel/hs-StateVar/buildlink3.mk"
.endif	# HS_CONTRAVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contravariant
