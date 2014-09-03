# $NetBSD: buildlink3.mk,v 1.1 2014/09/03 21:16:55 szptvlfn Exp $

BUILDLINK_TREE+=	hs-void

.if !defined(HS_VOID_BUILDLINK3_MK)
HS_VOID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-void+=	hs-void>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-void+=	hs-void>=0.6.1
BUILDLINK_PKGSRCDIR.hs-void?=	../../devel/hs-void

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_VOID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-void
