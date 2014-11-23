# $NetBSD: buildlink3.mk,v 1.5 2014/11/23 12:52:32 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.10
BUILDLINK_ABI_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.10nb1
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../devel/hs-cmdargs

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
