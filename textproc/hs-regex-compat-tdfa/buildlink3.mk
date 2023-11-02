# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:37:35 pho Exp $

BUILDLINK_TREE+=	hs-regex-compat-tdfa

.if !defined(HS_REGEX_COMPAT_TDFA_BUILDLINK3_MK)
HS_REGEX_COMPAT_TDFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-compat-tdfa+=	hs-regex-compat-tdfa>=0.95.1
BUILDLINK_ABI_DEPENDS.hs-regex-compat-tdfa+=	hs-regex-compat-tdfa>=0.95.1.4nb4
BUILDLINK_PKGSRCDIR.hs-regex-compat-tdfa?=	../../textproc/hs-regex-compat-tdfa

.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.endif	# HS_REGEX_COMPAT_TDFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-compat-tdfa
