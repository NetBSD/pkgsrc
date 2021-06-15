# $NetBSD: blas.buildlink3.mk,v 1.2 2021/06/15 04:41:51 thor Exp $
#
# This Makefile fragment is meant to be included by packages that use any
# BLAS (Basic Linear Algebra System) implementation instead of one particular
# one.
#
# Since pkgsrc always ships BLAS and LAPACK together (as upstream
# implementations do), this adds both BLAS_LIBS and LAPACK_LIBS to the linker
# flags.  Often, they will be identical or at least redundant. LAPACK_LIBS
# does include BLAS_LIBS, in any case.
#
# The C interfaces CBLAS and LAPACKE are also selected
# via BLAS_C_INTERFACE in the package and respective CBLAS_LIBS and
# LAPACKE_LIBS are set. Also, BLAS_INCLUDES is set to preprocessor
# flags to locate/use respective headers.
#
# Note that use of the Accelerate framework is experimental and only
# attempted if user and package explicitly want it.
#
# Keywords: blas lapack netlib atlas openblas mkl
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
#    openblas_openmp, accelerate.framework
#    (Accelerate has differing API and needs special handling, might
#    be supported in a few specific packages ony.)
#
#  Default: All currently supported implementations (${_BLAS_TYPES})
#    except accelerate.framework
#
# === Package-settable variables ===
#
# BLAS_ACCEPTED
#   This is a list of blas packages that are compatible with the current
#   package. If not set, any BLAS implementation is OK.
#   Typically set in package Makefile.
#
# BLAS_C_INTERFACE
#   Set to yes if the package requires CBLAS or LAPACKE. This defines
#   BLAS_INCLUDES and pulls in additional packages for netlib. Optimized
#   implementations include the C interfaces in the main library anyway,
#   but you still have the effect on BLAS_INCLUDES.
#
# BLAS_INDEX64
#   Set to yes if the package wants to utilize 64 bit indices.
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
#   (including BLAS)
# CBLAS_LIBS
#   Linker flags used for linking to CBLAS library
#   (including BLAS)
# LAPACKE_LIBS
#   Linker flags used for linking to LAPACKE library
#   (including BLAS and LAPACK)
# BLAS_INCLUDES
#   Preprocessor flags to locate/use C interfaces
#   (both for CBLAS and LAPACKE)

.if !defined(MK_BLAS_BUILDLINK3_MK)
MK_BLAS_BUILDLINK3_MK=

BUILD_DEFS+=		PKGSRC_BLAS_TYPES
BUILD_DEFS_EFFECTS+=	BLAS_TYPE BLAS_LIBS LAPACK_LIBS \
			CBLAS_LIBS LAPACKE_LIBS BLAS_INCLUDES

.include "../../mk/bsd.prefs.mk"

# List of all possible BLAS choices, in order of *DEFAULT* preference.
# netlib is the reference implementation to which all others conform and
# should come first by default for maximum compatibility.  It is also the
# slowest and not desirable in many situations.  Users can override by setting
# PKGSRC_BLAS_TYPES. (See comment above)
_BLAS_TYPES=	netlib openblas openblas_pthread openblas_openmp
# The Accelerate framework is special, as it does not offer BLAS API compatible
# to the others. See liboctave/util/blaswrap.c in octave sources, or 
# the wrapper https://github.com/mcg1969/vecLibFort that one might want to
# package.
# We have it as option only if user explicitly set it in PKGSRC_BLAS_TYPES
# and the package accepts it explicitly.

BLAS_ACCEPTED?=	${_BLAS_TYPES}
PKGSRC_BLAS_TYPES?= ${_BLAS_TYPES}

.if !empty(BLAS_INDEX64:Myes)
_BLAS_64=	64
.else
_BLAS_64=
.endif

_BLAS_MATCH=
.for b in ${PKGSRC_BLAS_TYPES}
# Seems like Accelerate does not offer a 64 bit interface (yet?).
# Exclude from list in that case, even if present.
.  if ${b} != "accelerate.framework" || ( empty(_BLAS_64) \
   && exists(/System/Library/Frameworks/Accelerate.framework) )
_BLAS_MATCH+=	${BLAS_ACCEPTED:M${b}}
.  endif
.endfor
.if !empty(_BLAS_MATCH)
BLAS_TYPE=	${_BLAS_MATCH:[1]}
.else
BLAS_TYPE=	none
.endif

.if ${BLAS_TYPE} == "netlib"
_BLAS_PKGPATH=		math/lapack${_BLAS_64}
_CBLAS_PKGPATH=		math/cblas${_BLAS_64}
_LAPACKE_PKGPATH=	math/lapacke${_BLAS_64}
BLAS_LIBS=		-lblas${_BLAS_64}
LAPACK_LIBS=		-llapack${_BLAS_64} ${BLAS_LIBS}
CBLAS_LIBS=		-lcblas${_BLAS_64} ${BLAS_LIBS}
LAPACKE_LIBS=		-llapacke${_BLAS_64} ${LAPACK_LIBS}
BLAS_INCLUDES=		-I${PREFIX}/include/netlib${_BLAS_64}
.  if ${_BLAS_64} == "64"
BLAS_INCLUDES+= -DWeirdNEC -DHAVE_LAPACK_CONFIG_H -DLAPACK_ILP64
.  endif
.elif ${BLAS_TYPE} == "openblas"
_BLAS_PKGPATH=	math/openblas${_BLAS_64}
BLAS_LIBS=	-lopenblas${_BLAS_64}
LAPACK_LIBS=	${BLAS_LIBS}
CBLAS_LIBS=	${BLAS_LIBS}
LAPACKE_LIBS=	${BLAS_LIBS}
BLAS_INCLUDES=	-I${PREFIX}/include/openblas${_BLAS_64}
.elif ${BLAS_TYPE} == "openblas_pthread"
_BLAS_PKGPATH=	math/openblas${_BLAS_64}_pthread
BLAS_LIBS=	-lopenblas${_BLAS_64}_pthread
LAPACK_LIBS=	${BLAS_LIBS}
CBLAS_LIBS=	${BLAS_LIBS}
LAPACKE_LIBS=	${BLAS_LIBS}
BLAS_INCLUDES=	-I${PREFIX}/include/openblas64_pthread
.elif ${BLAS_TYPE} == "openblas_openmp"
_BLAS_PKGPATH=	math/openblas${_BLAS_64}_openmp
BLAS_LIBS=	-lopenblas${_BLAS_64}_openmp
LAPACK_LIBS=	${BLAS_LIBS}
CBLAS_LIBS=	${BLAS_LIBS}
LAPACKE_LIBS=	${BLAS_LIBS}
BLAS_INCLUDES=	-I${PREFIX}/include/openblas${_BLAS_64}_openmp
.elif ${BLAS_TYPE} == "accelerate.framework"
# No 64 bit variant yet. Excluded above.
# Actually, only CBLAS_LIBS is safe to use. Others have g77/f2c calling
# conventions, not gfortran. This needs custom handling in packages. 
BLAS_LIBS=	-framework Accelerate
CBLAS_LIBS=	${BLAS_LIBS}
LAPACK_LIBS=	${BLAS_LIBS}
LAPACKE_LIBS=	# build a wrapper for that?
BLAS_INCLUDES=	# not delivered yet
# Idea for cblas.h including Accelerate/Accelerate.h (would work the same
# for Intel MKL with -DBLASWRAP_MKL for mkl_cblas.h).
#BLAS_INCLUDES=	-I${PREFIX}/include/blaswrap -DBLASWRAP_ACCELERATE
.else # invalid or unimplemented type
PKG_FAIL_REASON+=	\
	"There is no acceptable BLAS for ${PKGNAME} in: ${PKGSRC_BLAS_TYPES}."
.endif

.if defined(_BLAS_PKGPATH)
.include "../../${_BLAS_PKGPATH}/buildlink3.mk"
.endif

.if !empty(BLAS_C_INTERFACE:Myes)
.  if defined(_CBLAS_PKGPATH)
.    include "../../${_CBLAS_PKGPATH}/buildlink3.mk"
.  endif
.  if defined(_LAPACKE_PKGPATH)
.    include "../../${_LAPACKE_PKGPATH}/buildlink3.mk"
.  endif
.else
.  undef	BLAS_INCLUDES
.endif

.endif # BLAS_BUILDLINK3_MK
