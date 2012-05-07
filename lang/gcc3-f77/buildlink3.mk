# $NetBSD: buildlink3.mk,v 1.19 2012/05/07 01:53:40 dholland Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	gcc3-f77

.if !defined(GCC3_F77_BUILDLINK3_MK)
GCC3_F77_BUILDLINK3_MK:=

.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_API_DEPENDS.gcc3-f77+=	gcc3${GCC3_PKGMODIF}-f77>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc3-f77+=	gcc3-f77>=3.3.5nb2
BUILDLINK_PKGSRCDIR.gcc3-f77?=	../../lang/gcc3-f77
BUILDLINK_LIBDIRS.gcc3-f77?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-f77}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-f77+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-f77?=	build
.  endif
.endif # GCC3_F77_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc3-f77
