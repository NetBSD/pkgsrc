# $NetBSD: buildlink3.mk,v 1.17 2026/11/13 14:39:18 pho Exp $

BUILDLINK_TREE+=	hs-splitmix

.if !defined(HS_SPLITMIX_BUILDLINK3_MK)
HS_SPLITMIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.1nb4
BUILDLINK_PKGSRCDIR.hs-splitmix?=	../../devel/hs-splitmix
.endif	# HS_SPLITMIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-splitmix
