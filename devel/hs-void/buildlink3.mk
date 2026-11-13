# $NetBSD: buildlink3.mk,v 1.22 2026/11/13 14:39:26 pho Exp $

BUILDLINK_TREE+=	hs-void

.if !defined(HS_VOID_BUILDLINK3_MK)
HS_VOID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-void+=	hs-void>=0.7.3
BUILDLINK_ABI_DEPENDS.hs-void+=	hs-void>=0.7.3nb12
BUILDLINK_PKGSRCDIR.hs-void?=	../../devel/hs-void
.endif	# HS_VOID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-void
