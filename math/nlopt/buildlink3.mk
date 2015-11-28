# $NetBSD: buildlink3.mk,v 1.1 2015/11/28 07:33:38 wen Exp $

BUILDLINK_TREE+=	nlopt

.if !defined(NLOPT_BUILDLINK3_MK)
NLOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlopt+=	nlopt>=2.4.2
BUILDLINK_ABI_DEPENDS.nlopt+=	nlopt>=2.4.2
BUILDLINK_PKGSRCDIR.nlopt?=		../../math/nlopt
.endif # NLOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlopt
