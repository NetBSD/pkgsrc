# $NetBSD: buildlink3.mk,v 1.2 2019/07/31 18:56:18 brook Exp $

BUILDLINK_TREE+=	Rbitops

.if !defined(RBITOPS_BUILDLINK3_MK)
RBITOPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Rbitops+=	R-bitops>=1.0.6
BUILDLINK_PKGSRCDIR.Rbitops?=	../../math/R-bitops
.endif # RBITOPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-Rbitops
