# $NetBSD: buildlink3.mk,v 1.8 2025/03/05 03:39:28 pho Exp $

BUILDLINK_TREE+=	hs-shelly

.if !defined(HS_SHELLY_BUILDLINK3_MK)
HS_SHELLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-shelly+=	hs-shelly>=1.12.1
BUILDLINK_ABI_DEPENDS.hs-shelly+=	hs-shelly>=1.12.1nb4
BUILDLINK_PKGSRCDIR.hs-shelly?=		../../devel/hs-shelly

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-enclosed-exceptions/buildlink3.mk"
.include "../../devel/hs-lifted-async/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.endif	# HS_SHELLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-shelly
