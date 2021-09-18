# $NetBSD: buildlink3.mk,v 1.3 2021/09/18 05:06:06 mef Exp $

BUILDLINK_TREE+=	nlopt

.if !defined(NLOPT_BUILDLINK3_MK)
NLOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlopt+=	nlopt>=2.6.2
BUILDLINK_ABI_DEPENDS.nlopt+=	nlopt>=2.6.2
BUILDLINK_PKGSRCDIR.nlopt?=	../../math/nlopt
.endif # NLOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlopt
