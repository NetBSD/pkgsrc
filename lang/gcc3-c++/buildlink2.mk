# $NetBSD: buildlink2.mk,v 1.2 2004/03/18 04:19:39 jlam Exp $

.if !defined(GCC3_CXX_BUILDLINK2_MK)
GCC3_CXX_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3-cxx
BUILDLINK_DEPENDS.gcc3-cxx?=	gcc3${GCC3_PKGMODIF}-c++>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3-cxx?=	../../lang/gcc3-c++

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-cxx+=	full
.else
BUILDLINK_DEPMETHOD.gcc3-cxx?=	build
.endif

BUILDLINK_PREFIX.gcc3-cxx=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3-cxx=	${_GCC_SUBPREFIX}include/c++/*/*
BUILDLINK_FILES.gcc3-cxx+=	${_GCC_SUBPREFIX}include/c++/*/*/*
BUILDLINK_FILES.gcc3-cxx+=	${_GCC_SUBPREFIX}include/c++/*/*/*/*
BUILDLINK_FILES.gcc3-cxx+=	${_GCC_SUBPREFIX}lib/libstdc++.*
BUILDLINK_FILES.gcc3-cxx+=	${_GCC_SUBPREFIX}lib/libsupc++.*

BUILDLINK_TARGETS+=	gcc3-cxx-buildlink
BUILDLINK_TARGETS+=     libstdc++-buildlink-la

gcc3-cxx-buildlink: _BUILDLINK_USE

libstdc++-buildlink-la:               
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libstdc++.la";			\
	libpattern="/usr/lib/libstdc++.*";				\
	${BUILDLINK_FAKE_LA}

.endif	# GCC3_CXX_BUILDLINK2_MK
