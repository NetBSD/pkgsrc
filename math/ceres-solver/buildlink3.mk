# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 16:12:54 ryoon Exp $

BUILDLINK_TREE+=	ceres-solver

.if !defined(CERES_SOLVER_BUILDLINK3_MK)
CERES_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ceres-solver+=	ceres-solver>=2.2.0
BUILDLINK_PKGSRCDIR.ceres-solver?=	../../math/ceres-solver

.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../math/suitesparse/buildlink3.mk"
.endif	# CERES_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ceres-solver
