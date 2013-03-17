# $NetBSD: buildlink3.mk,v 1.16 2013/03/17 17:08:51 asau Exp $

BUILDLINK_TREE+=	mpich

.if !defined(MPICH_BUILDLINK3_MK)
MPICH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpich+=	mpich>=3
BUILDLINK_PKGSRCDIR.mpich?=	../../parallel/mpi-ch

FIND_PREFIX:=	BUILDLINK_PREFIX.mpich=mpich
.include "../../mk/find-prefix.mk"

.include "../../parallel/openpa/buildlink3.mk"
.endif	# MPICH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpich
