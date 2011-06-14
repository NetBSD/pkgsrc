# $NetBSD: buildlink3.mk,v 1.1 2011/06/14 21:28:50 alnsn Exp $

BUILDLINK_TREE+=	Rbitops

.if !defined(RBITOPS_BUILDLINK3_MK)
RBITOPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Rbitops+=	R-bitops>=1.0.4.1
BUILDLINK_ABI_DEPENDS.Rbitops+=	R-bitops>=1.0.4.1
BUILDLINK_PKGSRCDIR.Rbitops?=	../../math/R-bitops
.endif # RBITOPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-Rbitops
