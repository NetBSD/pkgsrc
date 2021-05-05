# $NetBSD: buildlink3.mk,v 1.2 2021/05/05 16:19:08 pho Exp $

BUILDLINK_TREE+=	hs-foundation

.if !defined(HS_FOUNDATION_BUILDLINK3_MK)
HS_FOUNDATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-foundation+=	hs-foundation>=0.0.26
BUILDLINK_ABI_DEPENDS.hs-foundation+=	hs-foundation>=0.0.26nb1
BUILDLINK_PKGSRCDIR.hs-foundation?=	../../devel/hs-foundation

.include "../../devel/hs-basement/buildlink3.mk"
.endif	# HS_FOUNDATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-foundation
