# $NetBSD: buildlink3.mk,v 1.11 2025/01/29 17:44:17 pho Exp $

BUILDLINK_TREE+=	hs-assoc

.if !defined(HS_ASSOC_BUILDLINK3_MK)
HS_ASSOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-assoc+=	hs-assoc>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-assoc+=	hs-assoc>=1.1.1
BUILDLINK_PKGSRCDIR.hs-assoc?=		../../devel/hs-assoc
.endif	# HS_ASSOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-assoc
