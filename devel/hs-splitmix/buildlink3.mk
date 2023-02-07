# $NetBSD: buildlink3.mk,v 1.8 2023/02/07 01:40:50 pho Exp $

BUILDLINK_TREE+=	hs-splitmix

.if !defined(HS_SPLITMIX_BUILDLINK3_MK)
HS_SPLITMIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0.4nb3
BUILDLINK_PKGSRCDIR.hs-splitmix?=	../../devel/hs-splitmix
.endif	# HS_SPLITMIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-splitmix
