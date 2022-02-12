# $NetBSD: buildlink3.mk,v 1.8 2022/02/12 08:50:54 pho Exp $

BUILDLINK_TREE+=	hs-regex-posix

.if !defined(HS_REGEX_POSIX_BUILDLINK3_MK)
HS_REGEX_POSIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-posix+=	hs-regex-posix>=0.96.0
BUILDLINK_ABI_DEPENDS.hs-regex-posix+=	hs-regex-posix>=0.96.0.1nb1
BUILDLINK_PKGSRCDIR.hs-regex-posix?=	../../textproc/hs-regex-posix

.include "../../textproc/hs-regex-base/buildlink3.mk"
.endif	# HS_REGEX_POSIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-posix
