# $NetBSD: buildlink3.mk,v 1.12 2025/02/02 13:04:56 pho Exp $

BUILDLINK_TREE+=	hs-assoc

.if !defined(HS_ASSOC_BUILDLINK3_MK)
HS_ASSOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-assoc+=	hs-assoc>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-assoc+=	hs-assoc>=1.1.1nb1
BUILDLINK_PKGSRCDIR.hs-assoc?=		../../devel/hs-assoc
.endif	# HS_ASSOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-assoc
