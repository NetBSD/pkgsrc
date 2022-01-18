# $NetBSD: buildlink3.mk,v 1.6 2022/01/18 02:48:28 pho Exp $

BUILDLINK_TREE+=	hs-regex-posix

.if !defined(HS_REGEX_POSIX_BUILDLINK3_MK)
HS_REGEX_POSIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-posix+=	hs-regex-posix>=0.96.0
BUILDLINK_ABI_DEPENDS.hs-regex-posix+=	hs-regex-posix>=0.96.0.0nb2
BUILDLINK_PKGSRCDIR.hs-regex-posix?=	../../textproc/hs-regex-posix

.include "../../textproc/hs-regex-base/buildlink3.mk"
.endif	# HS_REGEX_POSIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-posix
