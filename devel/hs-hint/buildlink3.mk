# $NetBSD: buildlink3.mk,v 1.3 2014/11/23 12:52:32 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hint

.if !defined(HS_HINT_BUILDLINK3_MK)
HS_HINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hint+=	hs-hint>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-hint+=	hs-hint>=0.4.2.0nb2
BUILDLINK_PKGSRCDIR.hs-hint?=	../../devel/hs-hint

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-ghc-mtl/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_HINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hint
