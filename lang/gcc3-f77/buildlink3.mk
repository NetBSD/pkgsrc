# $NetBSD: buildlink3.mk,v 1.5 2004/02/13 00:27:28 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCC3F77_BUILDLINK3_MK:=	${GCC3F77_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc3f77
.endif

.if !empty(GCC3F77_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_PACKAGES+=		gcc3f77
BUILDLINK_DEPENDS.gcc3f77+=	gcc3${GCC3_PKGMODIF}-f77>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3f77?=	../../lang/gcc3-f77
BUILDLINK_LIBDIRS.gcc3f77?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3f77}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3f77+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3f77?=	build
.  endif
.endif	# GCC3F77_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
