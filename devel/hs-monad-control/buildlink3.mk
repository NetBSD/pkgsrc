# $NetBSD: buildlink3.mk,v 1.6 2020/01/11 10:39:25 pho Exp $

BUILDLINK_TREE+=	hs-monad-control

.if !defined(HS_MONAD_CONTROL_BUILDLINK3_MK)
HS_MONAD_CONTROL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-control+=	hs-monad-control>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-monad-control+=	hs-monad-control>=1.0.2.3
BUILDLINK_PKGSRCDIR.hs-monad-control?=		../../devel/hs-monad-control

.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_MONAD_CONTROL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-control
