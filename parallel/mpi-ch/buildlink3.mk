# $NetBSD: buildlink3.mk,v 1.17 2013/04/30 06:59:27 asau Exp $

BUILDLINK_TREE+=	mpich

.if !defined(MPICH_BUILDLINK3_MK)
MPICH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich+=	mpich>=3
BUILDLINK_PKGSRCDIR.mpich?=	../../parallel/mpi-ch

MPI_PREFIX?=	$(BUILDLINK_PREFIX.mpich)
FIND_PREFIX:=	BUILDLINK_PREFIX.mpich=mpich
.include "../../mk/find-prefix.mk"

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich
