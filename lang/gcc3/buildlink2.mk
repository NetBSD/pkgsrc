# $NetBSD: buildlink2.mk,v 1.6 2003/07/13 13:04:10 grant Exp $

# do not directly include this file. .include "../../mk/gcc.buildlink2.mk"
# to ensure the correct gcc package is selected based on USE_GCC2 and
# USE_GCC3.

.if !defined(GCC3_BUILDLINK2_MK)
GCC3_BUILDLINK2_MK=	# defined

GCC_REQD?=			3.3
BUILDLINK_DEPENDS.gcc?=		gcc3>=${GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc?=	../../lang/gcc3

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.else
BUILDLINK_DEPMETHOD.gcc?=	build
.endif

BUILDLINK_PREFIX.gcc=	${LOCALBASE}

_GCC_SUBPREFIX=		gcc-3.3/
_GCC_PREFIX=		${BUILDLINK_PREFIX.gcc}/${_GCC_SUBPREFIX}
_GCC_LIBGCCDIR!= \
  dirname `${_GCC_PREFIX}bin/gcc --print-libgcc-file-name`
_GCC_ARCHSUBDIR= \
  ${_GCC_LIBGCCDIR:S|^${BUILDLINK_PREFIX.gcc}/${_GCC_SUBPREFIX}||}
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

# These files are from gcc-3.3.
BUILDLINK_FILES.gcc=	${_GCC_SUBPREFIX}include/c++/3.3/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}include/c++/3.3/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/include/*/*/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/lib*.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${_GCC_ARCHSUBDIR}/specs
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${MACHINE_GNU_PLATFORM}/include/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}${MACHINE_GNU_PLATFORM}/include/*/*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/lib-org-w3c-dom.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/lib-org-xml-sax.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libffi*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libfrtbegin.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libg2c.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libgcc_s.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libgcj.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libiberty.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libobjc.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libstdc++.*
BUILDLINK_FILES.gcc+=	${_GCC_SUBPREFIX}lib/libsupc++.*

BUILDLINK_TARGETS+=	gcc-buildlink

gcc-buildlink: _BUILDLINK_USE

.endif	# GCC3_BUILDLINK2_MK
