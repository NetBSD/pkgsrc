# $NetBSD: buildlink2.mk,v 1.3 2004/03/18 04:19:39 jlam Exp $

.if !defined(GCC3_F77_BUILDLINK2_MK)
GCC3_F77_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3-f77
BUILDLINK_DEPENDS.gcc3-f77?=	gcc3${GCC3_PKGMODIF}-f77>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3-f77?=	../../lang/gcc3-f77

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-f77+=	full
.else
BUILDLINK_DEPMETHOD.gcc3-f77?=	build
.endif

BUILDLINK_PREFIX.gcc3-f77=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3-f77=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/g2c.h
BUILDLINK_FILES.gcc3-f77+=	${_GCC_SUBPREFIX}lib/libfrtbegin.*
BUILDLINK_FILES.gcc3-f77+=	${_GCC_SUBPREFIX}lib/libg2c.*

BUILDLINK_TARGETS+=	gcc3-f77-buildlink

gcc3-f77-buildlink: _BUILDLINK_USE

.endif	# GCC3_F77_BUILDLINK2_MK
