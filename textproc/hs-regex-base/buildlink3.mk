# $NetBSD: buildlink3.mk,v 1.3 2014/11/23 12:52:33 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regex-base

.if !defined(HS_REGEX_BASE_BUILDLINK3_MK)
HS_REGEX_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.93.2
BUILDLINK_ABI_DEPENDS.hs-regex-base+=	hs-regex-base>=0.93.2nb1
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../textproc/hs-regex-base

.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-base
