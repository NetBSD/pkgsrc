# $NetBSD: buildlink3.mk,v 1.13 2025/02/02 13:05:48 pho Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-Diff+=	hs-Diff>=1.0.2nb1
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../textproc/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
