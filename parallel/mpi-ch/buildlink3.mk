# $NetBSD: buildlink3.mk,v 1.18 2015/11/25 12:52:26 jperkin Exp $

BUILDLINK_TREE+=	mpich

.if !defined(MPICH_BUILDLINK3_MK)
MPICH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich+=	mpich>=3
BUILDLINK_PKGSRCDIR.mpich?=	../../parallel/mpi-ch

MPI_PREFIX?=	$(BUILDLINK_PREFIX.mpich)

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich
