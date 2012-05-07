# $NetBSD: buildlink3.mk,v 1.19 2012/05/07 01:53:40 dholland Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	gcc3-objc

.if !defined(GCC3_OBJC_BUILDLINK3_MK)
GCC3_OBJC_BUILDLINK3_MK:=

.  if defined(GCC3_INSTALLTO_SUBPREFIX)
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_API_DEPENDS.gcc3-objc+=	gcc3${GCC3_PKGMODIF}-objc>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc3-objc+=	gcc3-objc>=3.3.5nb1
BUILDLINK_PKGSRCDIR.gcc3-objc?=	../../lang/gcc3-objc
BUILDLINK_LIBDIRS.gcc3-objc?=	\
	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-objc}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-objc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-objc?=	build
.  endif
.endif # GCC3_OBJC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc3-objc
