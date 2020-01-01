# $NetBSD: buildlink3.mk,v 1.7 2020/01/01 03:01:16 pho Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.20
BUILDLINK_ABI_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.20
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../devel/hs-cmdargs

.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
