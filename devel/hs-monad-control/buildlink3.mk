# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:03 rillig Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-monad-control+=	hs-monad-control>=0.3.3.0nb2
BUILDLINK_PKGSRCDIR.hs-monad-control?=		../../devel/hs-monad-control

.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
