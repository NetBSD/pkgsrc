# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GCC3_CXX_BUILDLINK3_MK:=	${GCC3_CXX_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc3-cxx
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngcc3-cxx}
BUILDLINK_PACKAGES+=	gcc3-cxx
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gcc3-cxx

.if !empty(GCC3_CXX_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_API_DEPENDS.gcc3-cxx+=	gcc3${GCC3_PKGMODIF}-c++>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc3-cxx?=	gcc3-c++>=3.3.5nb1
BUILDLINK_PKGSRCDIR.gcc3-cxx?=	../../lang/gcc3-c++
BUILDLINK_LIBDIRS.gcc3-cxx?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-cxx}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-cxx+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-cxx?=	build
.  endif
.endif	# GCC3_CXX_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
