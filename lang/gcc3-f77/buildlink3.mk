# $NetBSD: buildlink3.mk,v 1.10 2004/05/17 21:32:34 seb Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCC3_F77_BUILDLINK3_MK:=	${GCC3_F77_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc3-f77
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngcc3-f77}
BUILDLINK_PACKAGES+=	gcc3-f77

.if !empty(GCC3_F77_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_DEPENDS.gcc3-f77+=	gcc3${GCC3_PKGMODIF}-f77>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3-f77?=	../../lang/gcc3-f77
BUILDLINK_LIBDIRS.gcc3-f77?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-f77}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-f77+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-f77?=	build
.  endif
.endif	# GCC3_F77_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
