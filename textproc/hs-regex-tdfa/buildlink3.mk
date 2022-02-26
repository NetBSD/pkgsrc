# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:58:30 pho Exp $

BUILDLINK_TREE+=	hs-regex-tdfa

.if !defined(HS_REGEX_TDFA_BUILDLINK3_MK)
HS_REGEX_TDFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-tdfa+=	hs-regex-tdfa>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-regex-tdfa+=	hs-regex-tdfa>=1.3.1.1nb2
BUILDLINK_PKGSRCDIR.hs-regex-tdfa?=	../../textproc/hs-regex-tdfa

.include "../../textproc/hs-regex-base/buildlink3.mk"
.endif	# HS_REGEX_TDFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-tdfa
