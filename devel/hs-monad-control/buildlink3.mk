# $NetBSD: buildlink3.mk,v 1.1 2014/07/30 21:34:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=0.3.3
BUILDLINK_PKGSRCDIR.hs-monad-control?=	../../devel/hs-monad-control

.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
