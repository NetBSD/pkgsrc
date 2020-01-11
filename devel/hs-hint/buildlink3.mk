# $NetBSD: buildlink3.mk,v 1.6 2020/01/11 08:15:58 pho Exp $

BUILDLINK_TREE+=	hs-hint

.if !defined(HS_HINT_BUILDLINK3_MK)
HS_HINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hint+=	hs-hint>=0.9.0
BUILDLINK_ABI_DEPENDS.hs-hint+=	hs-hint>=0.9.0.2
BUILDLINK_PKGSRCDIR.hs-hint?=	../../devel/hs-hint

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_HINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hint
