# $NetBSD: buildlink3.mk,v 1.18 2024/04/17 16:14:01 adam Exp $

BUILDLINK_TREE+=	boost-mpi

.if !defined(BOOST_MPI_BUILDLINK3_MK)
BOOST_MPI_BUILDLINK3_MK:=

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-mpi+=	boost-mpi-1.85.*
BUILDLINK_ABI_DEPENDS.boost-mpi+=	boost-mpi>=1.85.0
BUILDLINK_PKGSRCDIR.boost-mpi?=		../../devel/boost-mpi

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.endif # BOOST_MPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-mpi
