# $NetBSD: buildlink3.mk,v 1.1 2020/01/01 03:41:02 pho Exp $

BUILDLINK_TREE+=	hs-splitmix

.if !defined(HS_SPLITMIX_BUILDLINK3_MK)
HS_SPLITMIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-splitmix+=	hs-splitmix>=0.0.3
BUILDLINK_ABI_DEPENDS.hs-splitmix+=	hs-splitmix>=0.0.3
BUILDLINK_PKGSRCDIR.hs-splitmix?=	../../devel/hs-splitmix

.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_SPLITMIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-splitmix
