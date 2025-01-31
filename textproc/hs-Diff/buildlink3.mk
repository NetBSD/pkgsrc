# $NetBSD: buildlink3.mk,v 1.12 2025/01/31 02:20:14 pho Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-Diff+=	hs-Diff>=1.0.2
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../textproc/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
