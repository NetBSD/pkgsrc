# $NetBSD: buildlink2.mk,v 1.13 2003/07/13 13:04:09 grant Exp $

# do not directly include this file. .include "../../mk/gcc.buildlink2.mk"
# to ensure the correct gcc package is selected based on USE_GCC2 and
# USE_GCC3.

.if !defined(GCC2_BUILDLINK2_MK)
GCC2_BUILDLINK2_MK=	# defined

# If you want to allow EGCS to satisfy the GCC requirement, then set
# GCC_REQD to "2.8.0".
#
GCC_REQD?=			2.95.3
BUILDLINK_DEPENDS.gcc?=		gcc>=${GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc?=	../../lang/gcc

# Packages that link against shared gcc libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.else
BUILDLINK_DEPMETHOD.gcc?=	build
.endif

BUILDLINK_PREFIX.gcc=	${LOCALBASE}

_GCC_SUBPREFIX=		gcc-2.95.3/
_GCC_PREFIX=		${BUILDLINK_PREFIX.gcc}/${_GCC_SUBPREFIX}
_GCC_ARCHSUBDIR=	lib/gcc-lib/${MACHINE_GNU_PLATFORM}/2.95.3
_GCC_ARCHDIR=		${_GCC_PREFIX}${_GCC_ARCHSUBDIR}

BUILDLINK_LDFLAGS.gcc=	-L${_GCC_ARCHDIR} -Wl,${RPATH_FLAG}${_GCC_ARCHDIR} -L${_GCC_PREFIX}lib -Wl,${RPATH_FLAG}${_GCC_PREFIX}lib

BUILDLINK_PACKAGES+=	gcc
PATH:=		${_GCC_PREFIX}bin:${PATH}
CC=		${_GCC_PREFIX}bin/gcc
CPP=		${_GCC_PREFIX}bin/cpp
CXX=		${_GCC_PREFIX}bin/g++
F77=		${_GCC_PREFIX}bin/g77
PKG_FC=		${F77}

.if defined(USE_GCC_SHLIB)
LDFLAGS+=		${BUILDLINK_LDFLAGS.gcc}
.endif
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

# These files are from gcc>=2.95.3.
BUILDLINK_FILES.gcc=	${_GCC_SUBPREFIX}include/g++-3/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}include/g++-3/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*/*/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/lib*.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/specs
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${MACHINE_GNU_PLATFORM}/include/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${MACHINE_GNU_PLATFORM}/include/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libiberty.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libstdc++.*

BUILDLINK_TARGETS+=	gcc-buildlink

gcc-buildlink: _BUILDLINK_USE

.endif	# GCC2_BUILDLINK2_MK
