# $NetBSD: buildlink3.mk,v 1.7 2023/02/07 01:41:07 pho Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-Diff+=	hs-Diff>=0.4.1nb3
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../textproc/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
