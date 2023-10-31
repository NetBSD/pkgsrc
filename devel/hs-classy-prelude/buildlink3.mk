# $NetBSD: buildlink3.mk,v 1.7 2023/10/31 03:32:06 pho Exp $

BUILDLINK_TREE+=	hs-classy-prelude

.if !defined(HS_CLASSY_PRELUDE_BUILDLINK3_MK)
HS_CLASSY_PRELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-classy-prelude+=	hs-classy-prelude>=1.5.0
BUILDLINK_ABI_DEPENDS.hs-classy-prelude+=	hs-classy-prelude>=1.5.0.3
BUILDLINK_PKGSRCDIR.hs-classy-prelude?=		../../devel/hs-classy-prelude

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-basic-prelude/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../devel/hs-chunked-data/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mono-traversable/buildlink3.mk"
.include "../../devel/hs-mono-traversable-instances/buildlink3.mk"
.include "../../devel/hs-mutable-containers/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-say/buildlink3.mk"
.include "../../devel/hs-stm-chans/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-instances/buildlink3.mk"
.endif	# HS_CLASSY_PRELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-classy-prelude
