# $NetBSD: buildlink2.mk,v 1.1 2004/02/12 16:50:53 recht Exp $
#

.if !defined(MPICH_BUILDLINK2_MK)
MPICH_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mpich
BUILDLINK_DEPENDS.mpich?=		mpich>=1.2.5.2
BUILDLINK_PKGSRCDIR.mpich?=		../../parallel/mpi-ch

EVAL_PREFIX+=	BUILDLINK_PREFIX.mpich=mpich
BUILDLINK_PREFIX.mpich_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mpich+=	include/mpi.h
BUILDLINK_FILES.mpich+=	include/mpi_errno.h
BUILDLINK_FILES.mpich+=	include/mpi_fortdefs.h
BUILDLINK_FILES.mpich+=	include/mpidefs.h
BUILDLINK_FILES.mpich+=	include/mpif.h
BUILDLINK_FILES.mpich+=	include/mpio.h
BUILDLINK_FILES.mpich+=	include/mpiof.h
BUILDLINK_FILES.mpich+=	include/mpi2c++/*.h
BUILDLINK_FILES.mpich+=	lib/libampe.*
BUILDLINK_FILES.mpich+=	lib/libfmpich.*
BUILDLINK_FILES.mpich+=	lib/liblmpe.*
BUILDLINK_FILES.mpich+=	lib/libmpe.*
BUILDLINK_FILES.mpich+=	lib/libmpe_nompi.*
BUILDLINK_FILES.mpich+=	lib/libmpich.*
BUILDLINK_FILES.mpich+=	lib/libmpichfsup.*
BUILDLINK_FILES.mpich+=	lib/libpmpich++.*
BUILDLINK_FILES.mpich+=	lib/libpmpich.*
BUILDLINK_FILES.mpich+=	lib/libtmpe.*
BUILDLINK_FILES.mpich+=	lib/mpe_prof.o

BUILDLINK_TARGETS+=	mpich-buildlink

mpich-buildlink: _BUILDLINK_USE

.endif	# MPICH_BUILDLINK2_MK
