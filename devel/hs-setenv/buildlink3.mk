# $NetBSD: buildlink3.mk,v 1.7 2026/11/13 14:39:16 pho Exp $

BUILDLINK_TREE+=	hs-setenv

.if !defined(HS_SETENV_BUILDLINK3_MK)
HS_SETENV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-setenv+=	hs-setenv>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-setenv+=	hs-setenv>=0.1.1.3nb6
BUILDLINK_PKGSRCDIR.hs-setenv?=		../../devel/hs-setenv
.endif	# HS_SETENV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-setenv
