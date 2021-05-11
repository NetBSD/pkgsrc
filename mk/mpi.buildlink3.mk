# $NetBSD: mpi.buildlink3.mk,v 1.6 2021/05/11 21:30:57 thor Exp $
#
# This Makefile fragment is meant to be included by packages
# that use any MPI implementation instead of one particular one.
# The available MPI implementations are "mpich" and "openmpi",
# or just whatever you have installed in the system (mpi wrapper
# compiler names are standardized).
#
# You have to decide on one implementation and stick to it. Especially
# with the native option, installing an MPI implementation from pkgsrc
# will break things for programs that you built before.
#
# User-settable variables:
#
# MPI_TYPE
#	This value represents the type of MPI we wish to use on the system.
#       Changing this value is only safe when you ensure that all MPI-using
#       packages are re-built, and if switching to native, the MPI package
#       from pkgsrc needs to be deinstalled first.
#
#	Possible: mpich, openmpi, native
#	Default: mpich

.if !defined(MPI_BUILDLINK3_MK)
MPI_BUILDLINK3_MK=	# define it

.include "../../mk/bsd.prefs.mk"

# Try to find if we have anything installed already
.if exists(${LOCALBASE}/bin/mpicc)
_INST_MPI_PACKAGE!=	${PKG_INFO} -Q PKGPATH -F ${LOCALBASE}/bin/mpicc
MPI_TYPE?=	${_INST_MPI_PACKAGE:T:S/-//}
.endif

MPI_TYPE?=	mpich	# default to MPICH due to backward compatibility
.if ${MPI_TYPE} == "native"
.  if exists(${LOCALBASE}/bin/mpicc)
PKG_FAIL_REASON+=	\
	"MPI installed from pkgsrc conflicts with native. Deinstall ${_INST_MPI_PACKAGE}."
.  endif
.elif ${MPI_TYPE} == "mpich"
_MPI_PACKAGE=	parallel/mpi-ch
.elif ${MPI_TYPE} == "openmpi"
_MPI_PACKAGE=	parallel/openmpi
.else # invalid or unimplemented type
PKG_FAIL_REASON+=	\
	"${MPI_TYPE} is not an acceptable MPI type for ${PKGNAME}."
.endif

.if defined(_MPI_PACKAGE)
.  if !defined(_INST_MPI_PACKAGE) || ${_INST_MPI_PACKAGE} == ${_MPI_PACKAGE}
.include "../../${_MPI_PACKAGE}/buildlink3.mk"
.  else
PKG_FAIL_REASON+=	\
	"Attempt to switch MPI type to ${MPI_TYPE} conflicting with installed ${_INST_MPI_PACKAGE}."
.  endif
.endif

.endif	# MPI_BUILDLINK3_MK
