# $NetBSD: buildlink3.mk,v 1.4 2023/08/11 08:31:20 mef Exp $

BUILDLINK_TREE+=	nlopt

.if !defined(NLOPT_BUILDLINK3_MK)
NLOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlopt+=	nlopt>=2.7.1
BUILDLINK_ABI_DEPENDS.nlopt+=	nlopt>=2.7.1
BUILDLINK_PKGSRCDIR.nlopt?=	../../math/nlopt
.endif # NLOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlopt
