# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCC3_JAVA_BUILDLINK3_MK:=	${GCC3_JAVA_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc3-java
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngcc3-java}
BUILDLINK_PACKAGES+=	gcc3-java
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gcc3-java

.if !empty(GCC3_JAVA_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_API_DEPENDS.gcc3-java+=	gcc3${GCC3_PKGMODIF}-java>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc3-java?=	gcc3-java>=3.3.5nb1
BUILDLINK_PKGSRCDIR.gcc3-java?=	../../lang/gcc3-java
BUILDLINK_LIBDIRS.gcc3-java?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-java}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-java+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-java?=	build
.  endif
.endif	# GCC3_JAVA_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
