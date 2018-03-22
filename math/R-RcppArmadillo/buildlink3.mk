# $NetBSD: buildlink3.mk,v 1.1 2018/03/22 15:36:04 minskim Exp $

BUILDLINK_TREE+=	R-RcppArmadillo

.if !defined(R_RCPPARMADILLO_BUILDLINK3_MK)
R_RCPPARMADILLO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-RcppArmadillo+=	R-RcppArmadillo>=0.8.300.1.0
BUILDLINK_PKGSRCDIR.R-RcppArmadillo?=	../../math/R-RcppArmadillo

.include "../../devel/R-Rcpp/buildlink3.mk"
.endif	# R_RCPPARMADILLO_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-RcppArmadillo
