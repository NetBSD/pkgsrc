# $NetBSD: buildlink3.mk,v 1.2 2014/07/28 21:35:23 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.9
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../devel/hs-cmdargs

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
