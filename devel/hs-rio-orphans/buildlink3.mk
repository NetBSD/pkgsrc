# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:32:10 pho Exp $

BUILDLINK_TREE+=	hs-rio-orphans

.if !defined(HS_RIO_ORPHANS_BUILDLINK3_MK)
HS_RIO_ORPHANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-rio-orphans+=	hs-rio-orphans>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-rio-orphans+=	hs-rio-orphans>=0.1.2.0nb8
BUILDLINK_PKGSRCDIR.hs-rio-orphans?=	../../devel/hs-rio-orphans

.include "../../sysutils/hs-fast-logger/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-monad-logger/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-rio/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.endif	# HS_RIO_ORPHANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-rio-orphans
