# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:44:48 riastradh Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-Diff+=	hs-Diff>=0.4.0
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../textproc/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
