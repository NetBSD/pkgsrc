# $NetBSD: buildlink3.mk,v 1.5 2004/02/13 00:27:28 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCC3OBJC_BUILDLINK3_MK:=	${GCC3OBJC_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc3objc
.endif

.if !empty(GCC3OBJC_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_PACKAGES+=		gcc3objc
BUILDLINK_DEPENDS+=		gcc3objc
BUILDLINK_DEPENDS.gcc3objc+=	gcc3${GCC3_PKGMODIF}-objc>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3objc?=	../../lang/gcc3-objc
BUILDLINK_LIBDIRS.gcc3objc?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3objc}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3objc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3objc?=	build
.  endif
.endif	# GCC3OBJC_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
