# $NetBSD: buildlink2.mk,v 1.1 2004/02/01 14:05:47 jlam Exp $

.if !defined(GCC3OBJC_BUILDLINK2_MK)
GCC3OBJC_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3objc
BUILDLINK_DEPENDS.gcc3objc?=	gcc3${GCC3_PKGMODIF}-objc>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3objc?=	../../lang/gcc3-objc

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3objc+=	full
.else
BUILDLINK_DEPMETHOD.gcc3objc?=	build
.endif

BUILDLINK_PREFIX.gcc3objc=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3objc=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/objc/*
BUILDLINK_FILES.gcc3objc+=	${_GCC_SUBPREFIX}/lib/libobjc.*

BUILDLINK_TARGETS+=	gcc3objc-buildlink

gcc3objc-buildlink: _BUILDLINK_USE

.endif	# GCC3OBJC_BUILDLINK2_MK
