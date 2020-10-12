# $NetBSD: blas.buildlink3.mk,v 1.1 2020/10/12 21:51:57 bacon Exp $
#
# This Makefile fragment is meant to be included by packages that use any BLAS
# (Basic Linear Algebra System) implementation instead of one particular one.
#
# Since pkgsrc always ships BLAS and LAPACK together (as upstream
# implementations do), this adds both BLAS_LIBS and LAPACK_LIBS to the linker
# flags.  Often, they will be identical or at least redundant. It is a matter
# of style to stay consistent in their use.
#
# Keywords: blas lapack atlas openblas mkl
#
# === User-settable variables ===
#
# PKGSRC_BLAS_TYPES
#  This value specifies an exhaustive list of BLAS implementations we wish to
#  use in this pkgsrc installation, in descending order of preference.
#  The implementation selected for a build will be the first one in
#  PKGSRC_BLAS_TYPES that also appears in BLAS_ACCEPTED (see below).
#  Typically set in mk.conf.
#
#  Possible: one or more of netlib, openblas, openblas_pthread,
#    openblas_openmp, and Apple's accelerate.framework
#    (to come: Intel MKL, other external optimized builds)
#
#  Default: All currently supported implementations (${_BLAS_TYPES})
#
# === Package-settable variables ===
#
# BLAS_ACCEPTED
#   This is a list of blas packages that are compatible with the current
#   package. If not set, any BLAS implementation is OK.
#   Typically set in package Makefile.
#
# === Variables automatically set here for use in package builds ===
# 
# BLAS_TYPE
#   This is the BLAS implementation chosen for a particular package build from
#   PKGSRC_BLAS_TYPES and BLAS_ACCEPTED.  If PKGSRC_BLAS_TYPES and
#   BLAS_ACCEPTED have no implementations in common, it defaults to none
#   and the build fails.
# BLAS_LIBS
#   Linker flags used for linking to BLAS library
# LAPACK_LIBS
#   Linker flags used for linking to LAPACK library

.if !defined(MK_BLAS_BUILDLINK3_MK)
MK_BLAS_BUILDLINK3_MK=

BUILD_DEFS+=		PKGSRC_BLAS_TYPES
BUILD_DEFS_EFFECTS+=	BLAS_TYPE BLAS_LIBS LAPACK_LIBS

# TODO: Upon commit change to: .include "bsd.prefs.mk"
.include "../../mk/bsd.prefs.mk"

# List of all possible BLAS choices, in order of *DEFAULT* preference.
# netlib is the reference implementation to which all others conform and
# should come first by default for maximum compatibility.  It is also the
# slowest and not desirable in many situations.  Users can override by setting
# PKGSRC_BLAS_TYPES. (See comment above)
_BLAS_TYPES=	netlib openblas openblas_pthread openblas_openmp
# Darwin
.if exists(/System/Library/Frameworks/Accelerate.framework)
_BLAS_TYPES+=	accelerate.framework
.endif

BLAS_ACCEPTED?=	${_BLAS_TYPES}
PKGSRC_BLAS_TYPES?= ${_BLAS_TYPES}

_BLAS_MATCH=
.for b in ${PKGSRC_BLAS_TYPES}
_BLAS_MATCH+=	${BLAS_ACCEPTED:M${b}}
.endfor
.if !empty(_BLAS_MATCH)
BLAS_TYPE=	${_BLAS_MATCH:[1]}
.else
BLAS_TYPE=	none
.endif

.if ${BLAS_TYPE} == "netlib"
_BLAS_PKGPATH=	math/lapack
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack ${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas"
_BLAS_PKGPATH=	math/openblas
BLAS_LIBS=	-lopenblas
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas_pthread"
_BLAS_PKGPATH=	math/openblas_pthread
BLAS_LIBS=	-lopenblas_pthread
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas_openmp"
_BLAS_PKGPATH=	math/openblas_openmp
BLAS_LIBS=	-lopenblas_openmp
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "accelerate.framework"
BLAS_LIBS=	-framework Accelerate
LAPACK_LIBS=	${BLAS_LIBS}
.else # invalid or unimplemented type
PKG_FAIL_REASON+=	\
	"There is no acceptable BLAS for ${PKGNAME} in: ${PKGSRC_BLAS_TYPES}."
.endif

.if defined(_BLAS_PKGPATH)
.include "../../${_BLAS_PKGPATH}/buildlink3.mk"
.endif

.endif # BLAS_BUILDLINK3_MK
