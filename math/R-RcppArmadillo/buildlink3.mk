# $NetBSD: buildlink3.mk,v 1.2 2019/07/31 18:39:23 brook Exp $

BUILDLINK_TREE+=	R-RcppArmadillo

.if !defined(R_RCPPARMADILLO_BUILDLINK3_MK)
R_RCPPARMADILLO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-RcppArmadillo+=	R-RcppArmadillo>=0.9.600.4.0
BUILDLINK_PKGSRCDIR.R-RcppArmadillo?=	../../math/R-RcppArmadillo

.include "../../devel/R-Rcpp/buildlink3.mk"
.endif	# R_RCPPARMADILLO_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-RcppArmadillo
