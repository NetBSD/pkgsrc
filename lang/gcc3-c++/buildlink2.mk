# $NetBSD: buildlink2.mk,v 1.1 2004/02/01 14:05:47 jlam Exp $

.if !defined(GCC3CXX_BUILDLINK2_MK)
GCC3CXX_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3cxx
BUILDLINK_DEPENDS.gcc3cxx?=	gcc3${GCC3_PKGMODIF}-c++>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3cxx?=	../../lang/gcc3-c++

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3cxx+=	full
.else
BUILDLINK_DEPMETHOD.gcc3cxx?=	build
.endif

BUILDLINK_PREFIX.gcc3cxx=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3cxx=	${_GCC_SUBPREFIX}include/c++/*/*
BUILDLINK_FILES.gcc3cxx+=	${_GCC_SUBPREFIX}include/c++/*/*/*
BUILDLINK_FILES.gcc3cxx+=	${_GCC_SUBPREFIX}include/c++/*/*/*/*
BUILDLINK_FILES.gcc3cxx+=	${_GCC_SUBPREFIX}lib/libstdc++.*
BUILDLINK_FILES.gcc3cxx+=	${_GCC_SUBPREFIX}lib/libsupc++.*

BUILDLINK_TARGETS+=	gcc3cxx-buildlink
BUILDLINK_TARGETS+=     libstdc++-buildlink-la

gcc3cxx-buildlink: _BUILDLINK_USE

libstdc++-buildlink-la:               
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libstdc++.la";			\
	libpattern="/usr/lib/libstdc++.*";				\
	${BUILDLINK_FAKE_LA}

.endif	# GCC3CXX_BUILDLINK2_MK
