# $NetBSD: buildlink2.mk,v 1.2 2004/03/18 04:19:39 jlam Exp $

.if !defined(GCC3_OBJC_BUILDLINK2_MK)
GCC3_OBJC_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3-objc
BUILDLINK_DEPENDS.gcc3-objc?=	gcc3${GCC3_PKGMODIF}-objc>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3-objc?=	../../lang/gcc3-objc

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-objc+=	full
.else
BUILDLINK_DEPMETHOD.gcc3-objc?=	build
.endif

BUILDLINK_PREFIX.gcc3-objc=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3-objc=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/objc/*
BUILDLINK_FILES.gcc3-objc+=	${_GCC_SUBPREFIX}/lib/libobjc.*

BUILDLINK_TARGETS+=	gcc3-objc-buildlink

gcc3-objc-buildlink: _BUILDLINK_USE

.endif	# GCC3_OBJC_BUILDLINK2_MK
