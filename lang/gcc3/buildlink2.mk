# $NetBSD: buildlink2.mk,v 1.2 2003/05/28 13:24:35 grant Exp $

.if !defined(GCC3_BUILDLINK2_MK)
GCC3_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

GCC_REQD?=			3.3
BUILDLINK_DEPENDS.gcc?=		gcc3>=${GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc?=	../../lang/gcc3

# Packages that use the C++ compiler and subsequently link against the
# shared libstdc++ from the package need a full dependency.
#
.if defined(USE_CXX)
BUILDLINK_DEPMETHOD.gcc+=	full
.else
BUILDLINK_DEPMETHOD.gcc?=	build
.endif

BUILDLINK_PREFIX.gcc=	${LOCALBASE}

_GCC_SUBPREFIX=		gcc-3.3/
_GCC_PREFIX=		${BUILDLINK_PREFIX.gcc}/${_GCC_SUBPREFIX}
_GCC_ARCHSUBDIR=	lib/gcc-lib/${MACHINE_GNU_PLATFORM}/3.3
_GCC_ARCHDIR=		${_GCC_PREFIX}${_GCC_ARCHSUBDIR}

BUILDLINK_LDFLAGS.gcc=	-L${_GCC_ARCHDIR} -Wl,${RPATH_FLAG}${_GCC_ARCHDIR} -L${_GCC_PREFIX}lib -Wl,${RPATH_FLAG}${_GCC_PREFIX}lib

_GCC_VERSION!=		( ${CC} -dumpversion ) 2>/dev/null || ${ECHO} 0

GCC_VERSION=		${_GCC_VERSION}
GCC_PKG=		gcc-${GCC_VERSION}

.if defined(USE_PKGSRC_GCC)
_NEED_PKGSRC_GCC=	YES
.else
_NEED_PKGSRC_GCC!= \
	if ${PKG_ADMIN} pmatch '${BUILDLINK_DEPENDS.gcc}' ${GCC_PKG}; then \
		gccpath=`${TYPE} gcc | ${AWK} '{ print $$NF }'`;	\
		if [ "$$gccpath" = "${_GCC_PREFIX}bin/gcc" ]; then \
			${ECHO} "YES";					\
		else							\
			${ECHO} "NO";					\
		fi;							\
	else								\
		${ECHO} "YES";						\
	fi
.endif

.if ${_NEED_PKGSRC_GCC} == "YES"
BUILDLINK_PACKAGES+=	gcc
PATH:=		${_GCC_PREFIX}bin:${PATH}
CC=		${_GCC_PREFIX}bin/gcc
CPP=		${_GCC_PREFIX}bin/cpp
CXX=		${_GCC_PREFIX}bin/g++
F77=		${_GCC_PREFIX}bin/g77
PKG_FC=		${F77}

.  if defined(USE_CXX)
LDFLAGS+=		${BUILDLINK_LDFLAGS.gcc}
.  endif
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH
.endif	# _NEED_PKGSRC_GCC == YES

# These files are from gcc-3.3.
BUILDLINK_FILES.gcc=	${_GCC_SUBPREFIX}include/c++/3.3/*
BUILDLINK_FILES.gcc=	${_GCC_SUBPREFIX}include/c++/3.3/*/*
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
