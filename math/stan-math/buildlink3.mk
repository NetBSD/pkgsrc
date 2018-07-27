# $NetBSD: buildlink3.mk,v 1.1 2018/07/27 06:49:25 minskim Exp $

BUILDLINK_TREE+=	stan-math

.if !defined(STAN_MATH_BUILDLINK3_MK)
STAN_MATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stan-math+=	stan-math>=2.17.1
BUILDLINK_DEPMETHOD.stan-math?=		build
BUILDLINK_PKGSRCDIR.stan-math?=		../../math/stan-math

.include "../../math/eigen3/buildlink3.mk"
.endif	# STAN_MATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-stan-math
