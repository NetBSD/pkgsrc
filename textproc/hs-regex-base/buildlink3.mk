# $NetBSD: buildlink3.mk,v 1.6 2021/04/24 06:49:43 pho Exp $

BUILDLINK_TREE+=	hs-regex-base

.if !defined(HS_REGEX_BASE_BUILDLINK3_MK)
HS_REGEX_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.94.0
BUILDLINK_ABI_DEPENDS.hs-regex-base+=	hs-regex-base>=0.94.0.1
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../textproc/hs-regex-base
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-base
