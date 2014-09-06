# $NetBSD: buildlink3.mk,v 1.20 2014/09/06 08:20:28 jperkin Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	gcc3-cxx

.if !defined(GCC3_CXX_BUILDLINK3_MK)
GCC3_CXX_BUILDLINK3_MK:=

.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_API_DEPENDS.gcc3-cxx+=	gcc3${GCC3_PKGMODIF}-c++>=3.0
BUILDLINK_ABI_DEPENDS.gcc3-cxx+=	gcc3-c++>=3.3.5nb1
BUILDLINK_PKGSRCDIR.gcc3-cxx?=	../../lang/gcc3-c++
BUILDLINK_LIBDIRS.gcc3-cxx?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-cxx}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-cxx+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-cxx?=	build
.  endif
.endif # GCC3_CXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc3-cxx
