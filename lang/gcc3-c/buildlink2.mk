# $NetBSD: buildlink2.mk,v 1.4 2004/02/02 12:17:23 jlam Exp $

.if !defined(GCC3C_BUILDLINK2_MK)
GCC3C_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3c
BUILDLINK_DEPENDS.gcc3c?=	gcc3${GCC3_PKGMODIF}-c>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3c?=	../../lang/gcc3-c

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3c+=	full
.else
BUILDLINK_DEPMETHOD.gcc3c?=	build
.endif

BUILDLINK_PREFIX.gcc3c=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3c=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*/*/*/*
BUILDLINK_FILES.gcc3c+=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*/*/*
BUILDLINK_FILES.gcc3c+=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*/*
BUILDLINK_FILES.gcc3c+=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*
BUILDLINK_FILES.gcc3c+=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/lib*.*
BUILDLINK_FILES.gcc3c+=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/specs
BUILDLINK_FILES.gcc3c+=	${_GCC_SUBPREFIX}lib/libgcc_s.*

BUILDLINK_TARGETS+=	gcc3c-buildlink

gcc3c-buildlink: _BUILDLINK_USE

.endif	# GCC3C_BUILDLINK2_MK
