# $NetBSD: buildlink3.mk,v 1.12 2023/11/02 06:36:30 pho Exp $

BUILDLINK_TREE+=	hs-foundation

.if !defined(HS_FOUNDATION_BUILDLINK3_MK)
HS_FOUNDATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-foundation+=	hs-foundation>=0.0.30
BUILDLINK_ABI_DEPENDS.hs-foundation+=	hs-foundation>=0.0.30nb1
BUILDLINK_PKGSRCDIR.hs-foundation?=	../../devel/hs-foundation

.include "../../devel/hs-basement/buildlink3.mk"
.endif	# HS_FOUNDATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-foundation
