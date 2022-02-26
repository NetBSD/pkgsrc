# $NetBSD: buildlink3.mk,v 1.11 2022/02/26 03:58:29 pho Exp $

BUILDLINK_TREE+=	hs-regex-base

.if !defined(HS_REGEX_BASE_BUILDLINK3_MK)
HS_REGEX_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.94.0
BUILDLINK_ABI_DEPENDS.hs-regex-base+=	hs-regex-base>=0.94.0.2nb2
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../textproc/hs-regex-base
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-base
