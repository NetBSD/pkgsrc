# $Id: optimize_gcc.mk,v 1.1 2003/05/29 11:45:50 abs Exp $

# This file is 'experimental' - which is doublespeak for unspeakably
# ugly, and probably quite broken by design.
#
# The intention is to pass additional flags to gcc to further optimise
# generated code. It _will_ make it impossible to debug, may fail to
# compile some code, and even generate curdled binaries. It is completely
# unsupported. Any questions should be directed to <abs@netbsd.org>.

.if (${MACHINE} == sparc64)
COPT_FLAGS=
.elif defined(USE_GCC3)
# With at least -march=k6-2, gcc 3.3 breaks with -frename-registers (in -O3)
COPT_FLAGS=-O2 -finline-functions
.else
COPT_FLAGS=-O3
.endif

.ifdef BSD_PKG_MK			# Try to catch various package opts

# This is a horrible mess, but how else to adjust per package?

.if !defined(PKGBASE)
PKGBASE=${PKGNAME:C/-[^-]*$//}
.if ${PKGBASE} == "" 
PKGBASE=${.CURDIR:C:.*/::}
.endif
.endif

COPT_FLAGS+=-ffast-math

PKG_EXCLUDE_OMIT_FRAME_POINTER=lua4
.if defined(USE_GCC3)
PKG_EXCLUDE_OMIT_FRAME_POINTER+=mozilla phoenix qt3-libs kdeedu3
.endif

.if empty(PKG_EXCLUDE_OMIT_FRAME_POINTER:M${PKGBASE})
COPT_FLAGS+=-fomit-frame-pointer
.endif

CFLAGS+=${COPT_FLAGS}
CXXFLAGS+=${COPT_FLAGS}
MAKE_FLAGS+=CCOPTIONS="${COPT_FLAGS}"	# Override CCOPTIONS for imake

.else					# Assume in base system, only COPTS

COPT_FLAGS+=-fomit-frame-pointer
# Include ${DEFCOPTS} and set ?= to allow overriding in kernel builds
.if !defined(COPTS)
COPTS=${DEFCOPTS} ${COPT_FLAGS}
.else
COPTS+=${COPT_FLAGS}
.endif
.if defined(USE_GCC3)
DEFWARNINGS=no
.endif

.endif
