# $NetBSD: buildlink3.mk,v 1.8 2015/08/02 11:27:05 szptvlfn Exp $

BUILDLINK_TREE+=	hs-void

.if !defined(HS_VOID_BUILDLINK3_MK)
HS_VOID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-void+=	hs-void>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-void+=	hs-void>=0.6.1nb8
BUILDLINK_PKGSRCDIR.hs-void?=	../../devel/hs-void

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_VOID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-void
