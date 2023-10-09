# $NetBSD: buildlink3.mk,v 1.8 2023/10/09 04:54:47 pho Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-Diff+=	hs-Diff>=0.4.1nb4
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../textproc/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
