# $NetBSD: mpi.buildlink3.mk,v 1.1 2010/05/16 11:07:39 asau Exp $
#
# This Makefile fragment is meant to be included by packages
# that use any MPI implementation instead of one particular one.
# The available MPI implementations are "mpich" and "openmpi".
#
# === User-settable variables ===
#
# MPI_TYPE
#	This value represents the type of MPI we wish to use on the system.
#
#	Possible: mpich, openmpi
#	Default: mpich

.if !defined(MPI_BUILDLINK3_MK)
MPI_BUILDLINK3_MK=	# define it

.include "../../mk/bsd.prefs.mk"

# Try to find if we have anything installed already
.if exists($(LOCALBASE)/bin/mpicc)
_MPI_PACKAGE!=	$(PKG_INFO) -Q PKGPATH -F $(LOCALBASE)/bin/mpicc
MPI_TYPE?=	$(_MPI_PACKAGE:T)
.else

MPI_TYPE?=	mpich	# default to MPICH due to backward compatibility
.if $(MPI_TYPE) == "mpich"
_MPI_PACKAGE=	parallel/mpi-ch
.elif $(MPI_TYPE) == "openmpi"
_MPI_PACKAGE=	parallel/openmpi
.else # invalid or unimplemented type
PKG_FAIL_REASON=	\
	"${MPI_TYPE} is not an acceptable MPI type for ${PKGNAME}."
.endif
.endif

.include "../../$(_MPI_PACKAGE)/buildlink3.mk"

.endif	# MPI_BUILDLINK3_MK
