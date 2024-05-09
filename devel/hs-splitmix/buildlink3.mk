# $NetBSD: buildlink3.mk,v 1.12 2024/05/09 01:32:12 pho Exp $

BUILDLINK_TREE+=	hs-splitmix

.if !defined(HS_SPLITMIX_BUILDLINK3_MK)
HS_SPLITMIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0.5nb2
BUILDLINK_PKGSRCDIR.hs-splitmix?=	../../devel/hs-splitmix
.endif	# HS_SPLITMIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-splitmix
