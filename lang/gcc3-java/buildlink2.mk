# $NetBSD: buildlink2.mk,v 1.2 2004/03/18 04:19:39 jlam Exp $

.if !defined(GCC3_JAVA_BUILDLINK2_MK)
GCC3_JAVA_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3-java
BUILDLINK_DEPENDS.gcc3-java?=	gcc3${GCC3_PKGMODIF}-java>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3-java?=	../../lang/gcc3-java

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-java+=	full
.else
BUILDLINK_DEPMETHOD.gcc3-java?=	build
.endif

BUILDLINK_PREFIX.gcc3-java=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3-java=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/java/*
BUILDLINK_FILES.gcc3-java+=	${_GCC_SUBPREFIX}/lib/libjava.*

BUILDLINK_TARGETS+=	gcc3-java-buildlink

gcc3-java-buildlink: _BUILDLINK_USE

.endif	# GCC3_JAVA_BUILDLINK2_MK
