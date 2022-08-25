# $NetBSD: buildlink3.mk,v 1.1 2022/08/25 22:58:00 thor Exp $

BUILDLINK_TREE+=	scalapack

.if !defined(SCALAPACK_BUILDLINK3_MK)
SCALAPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scalapack+=	scalapack>=2.2.0
BUILDLINK_ABI_DEPENDS.scalapack+=	scalapack>=2.2.0
BUILDLINK_PKGSRCDIR.scalapack?=		../../math/scalapack

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"

.endif # SCALAPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-scalapack
