# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:58:24 pho Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-Diff+=	hs-Diff>=0.4.1nb2
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../textproc/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
