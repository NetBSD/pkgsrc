# $NetBSD: buildlink3.mk,v 1.11 2023/11/02 06:36:57 pho Exp $

BUILDLINK_TREE+=	hs-splitmix

.if !defined(HS_SPLITMIX_BUILDLINK3_MK)
HS_SPLITMIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0.5nb1
BUILDLINK_PKGSRCDIR.hs-splitmix?=	../../devel/hs-splitmix
.endif	# HS_SPLITMIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-splitmix
