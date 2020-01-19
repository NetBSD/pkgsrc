# $NetBSD: buildlink3.mk,v 1.1 2020/01/19 23:45:50 pho Exp $

BUILDLINK_TREE+=	hs-regex-tdfa

.if !defined(HS_REGEX_TDFA_BUILDLINK3_MK)
HS_REGEX_TDFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-tdfa+=	hs-regex-tdfa>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-regex-tdfa+=	hs-regex-tdfa>=1.3.1.0
BUILDLINK_PKGSRCDIR.hs-regex-tdfa?=	../../textproc/hs-regex-tdfa

.include "../../textproc/hs-regex-base/buildlink3.mk"
.endif	# HS_REGEX_TDFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-tdfa
