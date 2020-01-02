# $NetBSD: buildlink3.mk,v 1.4 2020/01/02 14:56:10 pho Exp $

BUILDLINK_TREE+=	hs-regex-base

.if !defined(HS_REGEX_BASE_BUILDLINK3_MK)
HS_REGEX_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.94.0
BUILDLINK_ABI_DEPENDS.hs-regex-base+=	hs-regex-base>=0.94.0.0
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../textproc/hs-regex-base

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-base
