# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:52 pho Exp $

BUILDLINK_TREE+=	hs-diff3

.if !defined(HS_DIFF3_BUILDLINK3_MK)
HS_DIFF3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-diff3+=	hs-diff3>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-diff3+=	hs-diff3>=0.3.1nb1
BUILDLINK_PKGSRCDIR.hs-diff3?=		../../textproc/hs-diff3

.include "../../textproc/hs-Diff/buildlink3.mk"
.endif	# HS_DIFF3_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-diff3
