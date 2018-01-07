# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:23 rillig Exp $

BUILDLINK_TREE+=	nlopt

.if !defined(NLOPT_BUILDLINK3_MK)
NLOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlopt+=	nlopt>=2.4.2
BUILDLINK_ABI_DEPENDS.nlopt+=	nlopt>=2.4.2
BUILDLINK_PKGSRCDIR.nlopt?=	../../math/nlopt
.endif # NLOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlopt
