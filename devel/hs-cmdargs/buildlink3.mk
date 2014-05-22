# $NetBSD: buildlink3.mk,v 1.1 2014/05/22 21:39:23 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.7
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../devel/hs-cmdargs

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
