# $NetBSD: buildlink2.mk,v 1.9 2003/09/12 15:54:44 grant Exp $

# Do not directly include this file in package Makefiles. It is
# automatically included when required based on USE_GCC3.

.if !defined(GCC3_BUILDLINK2_MK)
GCC3_BUILDLINK2_MK=	# defined

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
_GCC_PREFIX=		${BUILDLINK_PREFIX.gcc}/${_GCC_SUBPREFIX}
_GCC_LIBGCCDIR!=						\
  if [ -x ${_GCC_PREFIX}bin/gcc ]; then				\
    dirname `${_GCC_PREFIX}bin/gcc --print-libgcc-file-name`;	\
  else								\
    ${ECHO} not-defined;					\
  fi
_GCC_ARCHSUBDIR= \
  ${_GCC_LIBGCCDIR:S|^${BUILDLINK_PREFIX.gcc}/${_GCC_SUBPREFIX}||}

BUILDLINK_PACKAGES+=	gcc

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
