# $NetBSD: buildlink3.mk,v 1.10 2004/05/17 21:32:34 seb Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCC3_OBJC_BUILDLINK3_MK:=	${GCC3_OBJC_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc3-objc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngcc3-objc}
BUILDLINK_PACKAGES+=	gcc3-objc

.if !empty(GCC3_OBJC_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_DEPENDS.gcc3-objc+=	gcc3${GCC3_PKGMODIF}-objc>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3-objc?=	../../lang/gcc3-objc
BUILDLINK_LIBDIRS.gcc3-objc?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-objc}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-objc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-objc?=	build
.  endif
.endif	# GCC3_OBJC_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
