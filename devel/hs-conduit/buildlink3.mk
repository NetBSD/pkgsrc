# $NetBSD: buildlink3.mk,v 1.1 2020/01/03 07:52:17 pho Exp $

BUILDLINK_TREE+=	hs-conduit

.if !defined(HS_CONDUIT_BUILDLINK3_MK)
HS_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-conduit+=	hs-conduit>=1.2.13
BUILDLINK_ABI_DEPENDS.hs-conduit+=	hs-conduit>=1.2.13.1
BUILDLINK_PKGSRCDIR.hs-conduit?=	../../devel/hs-conduit

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-conduit
