# $NetBSD: buildlink3.mk,v 1.19 2017/04/29 18:18:52 adam Exp $

BUILDLINK_TREE+=	mpich

.if !defined(MPICH_BUILDLINK3_MK)
MPICH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich+=	mpich>=3
BUILDLINK_PKGSRCDIR.mpich?=	../../parallel/mpi-ch

MPI_PREFIX?=	${BUILDLINK_PREFIX.mpich}

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich
