# $NetBSD: buildlink3.mk,v 1.15 2026/11/13 14:38:47 pho Exp $

BUILDLINK_TREE+=	hs-assoc

.if !defined(HS_ASSOC_BUILDLINK3_MK)
HS_ASSOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-assoc+=	hs-assoc>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-assoc+=	hs-assoc>=1.1.1nb4
BUILDLINK_PKGSRCDIR.hs-assoc?=		../../devel/hs-assoc
.endif	# HS_ASSOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-assoc
