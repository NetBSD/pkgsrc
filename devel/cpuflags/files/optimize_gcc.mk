# $Id: optimize_gcc.mk,v 1.5 2003/06/08 18:48:24 abs Exp $

# This file is 'experimental' - which is doublespeak for unspeakably
# ugly, and probably quite broken by design.
#
# The intention is to pass additional flags to gcc to further optimise
# generated code. It _will_ make it impossible to debug, may fail to
# compile some code, and even generate curdled binaries. It is completely
# unsupported. Any questions should be directed to <abs@netbsd.org>.

.if defined(USE_GCC3) || (${MACHINE} != sparc64)
COPT_FLAGS=-O3
.else
COPT_FLAGS=
.endif

.ifdef BSD_PKG_MK			# Try to catch various package opts

# This is a horrible mess, but how else to adjust per package?

.if !defined(PKGBASE)
PKGBASE=${PKGNAME:C/-[^-]*$//}
.if ${PKGBASE} == "" 
PKGBASE=${.CURDIR:C:.*/::}
.endif
.endif

COPT_FLAGS+=-ffast-math -fomit-frame-pointer

PKG_EXCLUDE_RENAME_REGISTERS+=
PKG_EXCLUDE_OMIT_FRAME_POINTER+=lua4
.if defined(USE_GCC3) # 1.6.1 needs this, but not 1.6T
PKG_EXCLUDE_RENAME_REGISTERS+=ORBit mozilla pango perl5 perl58
.else
PKG_EXCLUDE_OMIT_FRAME_POINTER+=mozilla phoenix qt3-libs kdeedu3
.endif

.if !empty(PKG_EXCLUDE_OMIT_FRAME_POINTER:M${PKGBASE})
COPT_FLAGS:=    ${COPT_FLAGS:S/-fomit-frame-pointer//}
.endif

# -O3 implies -finline-functions and -frename-registers
.if !empty(PKG_EXCLUDE_RENAME_REGISTERS:M${PKGBASE})
COPT_FLAGS:=	${COPT_FLAGS:S/-O3/-finline-functions/}
.endif

CFLAGS+=${COPT_FLAGS}
CXXFLAGS+=${COPT_FLAGS}
MAKE_FLAGS+=CCOPTIONS="${COPT_FLAGS}"	# Override CCOPTIONS for imake

.else					# Assume in base system, only COPTS

.if ${USETOOLS:Uyes} == "no"
COPT_FLAGS+=-fomit-frame-pointer
# Include ${DEFCOPTS} and set ?= to allow overriding in kernel builds
.if !defined(COPTS)
COPTS=${DEFCOPTS} ${COPT_FLAGS}
.else
COPTS+=${COPT_FLAGS}
.endif
.endif

.if defined(USE_GCC3)
DEFWARNINGS=no
.endif

.endif
