# $NetBSD: buildlink3.mk,v 1.8 2023/10/29 11:58:03 pho Exp $

BUILDLINK_TREE+=	hs-unicode-collation

.if !defined(HS_UNICODE_COLLATION_BUILDLINK3_MK)
HS_UNICODE_COLLATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-collation+=	hs-unicode-collation>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-unicode-collation+=	hs-unicode-collation>=0.1.3.5
BUILDLINK_PKGSRCDIR.hs-unicode-collation?=	../../textproc/hs-unicode-collation

.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.endif	# HS_UNICODE_COLLATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-collation
