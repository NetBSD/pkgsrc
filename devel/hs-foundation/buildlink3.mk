# $NetBSD: buildlink3.mk,v 1.13 2024/05/09 01:31:55 pho Exp $

BUILDLINK_TREE+=	hs-foundation

.if !defined(HS_FOUNDATION_BUILDLINK3_MK)
HS_FOUNDATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-foundation+=	hs-foundation>=0.0.30
BUILDLINK_ABI_DEPENDS.hs-foundation+=	hs-foundation>=0.0.30nb2
BUILDLINK_PKGSRCDIR.hs-foundation?=	../../devel/hs-foundation

.include "../../devel/hs-basement/buildlink3.mk"
.endif	# HS_FOUNDATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-foundation
