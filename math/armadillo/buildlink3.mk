# $NetBSD: buildlink3.mk,v 1.1 2023/12/19 12:28:50 thor Exp $

BUILDLINK_TREE+=	armadillo

.if !defined(ARMADILLO_BUILDLINK3_MK)
ARMADILLO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.armadillo+=	armadillo>=4.45.2
BUILDLINK_ABI_DEPENDS.armadillo?=	armadillo>=4.45.2
BUILDLINK_PKGSRCDIR.armadillo?=		../../math/armadillo

.include "../../mk/blas.buildlink3.mk"
.include "../../math/superlu/buildlink3.mk"
.include "../../math/arpack-ng/buildlink3.mk"
.endif	# ARMADILLO_BUILDLINK3_MK

BUILDLINK_TREE+=	-armadillo
