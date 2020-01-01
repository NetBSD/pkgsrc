# $NetBSD: buildlink3.mk,v 1.1 2020/01/01 02:29:19 pho Exp $

BUILDLINK_TREE+=	hs-contravariant

.if !defined(HS_CONTRAVARIANT_BUILDLINK3_MK)
HS_CONTRAVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contravariant+=	hs-contravariant>=1.5.2
BUILDLINK_ABI_DEPENDS.hs-contravariant+=	hs-contravariant>=1.5.2
BUILDLINK_PKGSRCDIR.hs-contravariant?=	../../math/hs-contravariant

.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-StateVar/buildlink3.mk"
.endif	# HS_CONTRAVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contravariant
