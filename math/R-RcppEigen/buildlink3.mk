# $NetBSD: buildlink3.mk,v 1.3 2023/06/15 11:38:41 mef Exp $

BUILDLINK_TREE+=	R-RcppEigen

.if !defined(R_RCPPEIGEN_BUILDLINK3_MK)
R_RCPPEIGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-RcppEigen+=	R-RcppEigen>=0.3.3.9.3
BUILDLINK_PKGSRCDIR.R-RcppEigen?=	../../math/R-RcppEigen

.endif # R_RCPPEIGEN

BUILDLINK_TREE+=	-R-RcppEigen
