# $NetBSD: buildlink2.mk,v 1.6 2004/03/18 04:19:39 jlam Exp $

.if !defined(GCC3_C_BUILDLINK2_MK)
GCC3_C_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3-c
BUILDLINK_DEPENDS.gcc3-c?=	gcc3${GCC3_PKGMODIF}-c>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3-c?=	../../lang/gcc3-c

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-c+=	full
.else
BUILDLINK_DEPMETHOD.gcc3-c?=	build
.endif

BUILDLINK_PREFIX.gcc3-c=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3-c=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*/*/*/*
BUILDLINK_FILES.gcc3-c+=${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*/*/*
BUILDLINK_FILES.gcc3-c+=${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*/*
BUILDLINK_FILES.gcc3-c+=${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/*
BUILDLINK_FILES.gcc3-c+=${_GCC_SUBPREFIX}lib/gcc-lib/*/*/lib*.*
BUILDLINK_FILES.gcc3-c+=${_GCC_SUBPREFIX}lib/gcc-lib/*/*/specs
BUILDLINK_FILES.gcc3-c+=${_GCC_SUBPREFIX}lib/libgcc_s.*

BUILDLINK_PRE_TARGETS+=	gcc3-c-buildlink

gcc3-c-buildlink: _BUILDLINK_USE

.endif	# GCC3_C_BUILDLINK2_MK
