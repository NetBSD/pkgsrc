# $NetBSD: buildlink3.mk,v 1.5 2022/09/07 06:50:48 pho Exp $

BUILDLINK_TREE+=	hs-monad-logger

.if !defined(HS_MONAD_LOGGER_BUILDLINK3_MK)
HS_MONAD_LOGGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-logger+=	hs-monad-logger>=0.3.36
BUILDLINK_ABI_DEPENDS.hs-monad-logger+=	hs-monad-logger>=0.3.36nb4
BUILDLINK_PKGSRCDIR.hs-monad-logger?=	../../devel/hs-monad-logger

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../sysutils/hs-fast-logger/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-monad-loops/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-stm-chans/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.endif	# HS_MONAD_LOGGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-logger
