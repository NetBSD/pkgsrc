# $NetBSD: buildlink3.mk,v 1.6 2022/02/12 08:50:32 pho Exp $

BUILDLINK_TREE+=	hs-foundation

.if !defined(HS_FOUNDATION_BUILDLINK3_MK)
HS_FOUNDATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-foundation+=	hs-foundation>=0.0.26
BUILDLINK_ABI_DEPENDS.hs-foundation+=	hs-foundation>=0.0.26.1nb1
BUILDLINK_PKGSRCDIR.hs-foundation?=	../../devel/hs-foundation

.include "../../devel/hs-basement/buildlink3.mk"
.endif	# HS_FOUNDATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-foundation
