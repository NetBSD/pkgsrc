# $NetBSD: buildlink3.mk,v 1.6 2015/06/04 13:06:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.13
BUILDLINK_ABI_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.13
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../devel/hs-cmdargs

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
