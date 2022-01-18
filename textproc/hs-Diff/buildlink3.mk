# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:23 pho Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-Diff+=	hs-Diff>=0.4.0nb2
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../textproc/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
