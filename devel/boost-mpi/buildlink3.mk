# $NetBSD: buildlink3.mk,v 1.19 2024/10/04 03:45:39 ryoon Exp $

BUILDLINK_TREE+=	boost-mpi

.if !defined(BOOST_MPI_BUILDLINK3_MK)
BOOST_MPI_BUILDLINK3_MK:=

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-mpi+=	boost-mpi-1.85.*
BUILDLINK_ABI_DEPENDS.boost-mpi+=	boost-mpi>=1.86.0nb1
BUILDLINK_PKGSRCDIR.boost-mpi?=		../../devel/boost-mpi

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.endif # BOOST_MPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-mpi
