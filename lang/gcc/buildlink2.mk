# $NetBSD: buildlink2.mk,v 1.1 2002/09/27 13:07:13 jlam Exp $

.if !defined(GCC_BUILDLINK2_MK)
GCC_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# If you want to allow EGCS to satisfy the GCC requirement, then set
# GCC_REQD to "2.8.0".
#
GCC_REQD?=			2.95.3
BUILDLINK_DEPENDS.gcc?=		gcc>=${GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc?=	../../lang/gcc

# Packages that use the C++ compiler and subsequently link against the
# shared libstdc++ from the package need a full dependency.
#
.if defined(USE_CXX)
BUILDLINK_DEPMETHOD.gcc+=	full
.else
BUILDLINK_DEPMETHOD.gcc?=	build
.endif

.if ${OPSYS} == "SunOS"
BUILDLINK_PREFIX.gcc=	${LOCALBASE}
.else
BUILDLINK_PREFIX.gcc=	${LOCALBASE}/gcc-2.95.3
.endif

.if defined(USE_PKGSRC_GCC)
_NEED_PKGSRC_GCC=	YES
.else
_GCC_VERSION!=		( gcc --version ) 2>/dev/null || ${ECHO} 0
.  if !empty(_GCC_VERSION:Megcs-[0-9]*)
#
# Consider EGCS to be gcc-2.8.1, so it will match 'gcc>=2.8.0'.
#
_GCC_PKG=		gcc-2.8.1
.  else
_GCC_PKG=		gcc-${_GCC_VERSION}
.  endif
_NEED_PKGSRC_GCC!= \
	if ${PKG_ADMIN} pmatch '${BUILDLINK_DEPENDS.gcc}' ${_GCC_PKG}; then \
		gccpath=`${TYPE} gcc | ${AWK} '{ print $$NF }'`;	\
		if [ "$$gccpath" = "${BUILDLINK_PREFIX.gcc}/bin/gcc" ]; then \
			${ECHO} "YES";					\
		else							\
			${ECHO} "NO";					\
		fi;							\
	else								\
		echo "YES";						\
	fi
.endif

.if ${_NEED_PKGSRC_GCC} == "YES"
BUILDLINK_PACKAGES+=	gcc
PATH:=		${BUILDLINK_PREFIX.gcc}/bin:${PATH}
CC=		${BUILDLINK_PREFIX.gcc}/bin/gcc
CPP=		${BUILDLINK_PREFIX.gcc}/bin/cpp
CXX=		${BUILDLINK_PREFIX.gcc}/bin/g++
F77=		${BUILDLINK_PREFIX.gcc}/bin/g77
PKG_FC=		${F77}

BUILDLINK_LDFLAGS.gcc=	-Wl,-R${BUILDLINK_PREFIX.gcc}/lib
LDFLAGS+=		${BUILDLINK_LDFLAGS.gcc}
.endif	# _NEED_PKGSRC_GCC == YES

_GCC_ARCHSUBDIR=	lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${_GCC_VERSION}

# These file are from gcc>=2.95.3.
BUILDLINK_FILES.gcc=	include/g++-3/*
BUILDLINK_FILES.gcc+=	include/g++-3/*/*
BUILDLINK_FILES.gcc+=	${_GCC_ARCHSUBDIR}/include/*
BUILDLINK_FILES.gcc+=	${_GCC_ARCHSUBDIR}/include/*/*
BUILDLINK_FILES.gcc+=	${_GCC_ARCHSUBDIR}/include/*/*/*
BUILDLINK_FILES.gcc+=	${_GCC_ARCHSUBDIR}/include/*/*/*/*
BUILDLINK_FILES.gcc+=	${_GCC_ARCHSUBDIR}/lib*.*
BUILDLINK_FILES.gcc+=	${_GCC_ARCHSUBDIR}/specs
BUILDLINK_FILES.gcc+=	${MACHINE_GNU_PLATFORM}/include/*
BUILDLINK_FILES.gcc+=	${MACHINE_GNU_PLATFORM}/include/*/*
BUILDLINK_FILES.gcc+=	lib/libiberty.*
BUILDLINK_FILES.gcc+=	lib/libstdc++.*

BUILDLINK_TARGETS+=	gcc-buildlink

gcc-buildlink: _BUILDLINK_USE

.endif	# GCC_BUILDLINK2_MK
