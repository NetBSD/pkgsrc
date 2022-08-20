# $NetBSD: buildlink3.mk,v 1.4 2022/08/20 08:08:23 wiz Exp $

BUILDLINK_TREE+=	hs-unicode-collation

.if !defined(HS_UNICODE_COLLATION_BUILDLINK3_MK)
HS_UNICODE_COLLATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-collation+=	hs-unicode-collation>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-unicode-collation+=	hs-unicode-collation>=0.1.3.1nb3
BUILDLINK_PKGSRCDIR.hs-unicode-collation?=	../../textproc/hs-unicode-collation

.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.endif	# HS_UNICODE_COLLATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-collation
