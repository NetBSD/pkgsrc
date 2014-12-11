# $NetBSD: buildlink3.mk,v 1.3 2014/12/11 12:24:45 szptvlfn Exp $

BUILDLINK_TREE+=	hs-resourcet

.if !defined(HS_RESOURCET_BUILDLINK3_MK)
HS_RESOURCET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resourcet+=	hs-resourcet>=1.1.3
BUILDLINK_ABI_DEPENDS.hs-resourcet+=	hs-resourcet>=1.1.3.1
BUILDLINK_PKGSRCDIR.hs-resourcet?=	../../devel/hs-resourcet

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_RESOURCET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resourcet
