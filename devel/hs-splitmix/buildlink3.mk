# $NetBSD: buildlink3.mk,v 1.6 2022/02/12 08:50:38 pho Exp $

BUILDLINK_TREE+=	hs-splitmix

.if !defined(HS_SPLITMIX_BUILDLINK3_MK)
HS_SPLITMIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-splitmix+=	hs-splitmix>=0.1.0.4nb1
BUILDLINK_PKGSRCDIR.hs-splitmix?=	../../devel/hs-splitmix
.endif	# HS_SPLITMIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-splitmix
