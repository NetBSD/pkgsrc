# $NetBSD: buildlink3.mk,v 1.8 2022/01/18 02:48:10 pho Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-monad-control+=	hs-monad-control>=1.0.2.3nb2
BUILDLINK_PKGSRCDIR.hs-monad-control?=		../../devel/hs-monad-control

.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
