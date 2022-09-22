# $NetBSD: buildlink3.mk,v 1.21 2022/09/22 16:47:04 thor Exp $

BUILDLINK_TREE+=	mpich

.if !defined(MPICH_BUILDLINK3_MK)
MPICH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich+=	mpich>=3
BUILDLINK_ABI_DEPENDS.mpich?=	mpich>=3.2.1nb9
BUILDLINK_PKGSRCDIR.mpich?=	../../parallel/mpi-ch

BUILDLINK_FILES.mpich+=		include/*.mod

MPI_PREFIX?=	${BUILDLINK_PREFIX.mpich}

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich
