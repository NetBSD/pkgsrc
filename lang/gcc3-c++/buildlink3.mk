# $NetBSD: buildlink3.mk,v 1.1 2004/02/01 14:05:47 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCC3CXX_BUILDLINK3_MK:=	${GCC3CXX_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(GCC3CXX_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.  endif
BUILDLINK_PACKAGES+=		gcc3cxx
BUILDLINK_DEPENDS+=		gcc3cxx
BUILDLINK_DEPENDS.gcc3cxx+=	gcc3${GCC3_PKGMODIF}-c++>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3cxx?=	../../lang/gcc3-c++

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3cxx+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3cxx?=	build
.  endif
.endif	# GCC3CXX_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
