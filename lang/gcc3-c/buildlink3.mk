# $NetBSD: buildlink3.mk,v 1.18 2009/03/20 19:24:49 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	gcc3-c

.if !defined(GCC3_C_BUILDLINK3_MK)
GCC3_C_BUILDLINK3_MK:=

.  include "../../mk/bsd.prefs.mk"
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
#
# "gcc3" is the directory named in pkgsrc/lang/gcc3-c/Makefile.common"
# as GCC3_DEFAULT_SUBPREFIX.
#
.    if ${GCC3_INSTALLTO_SUBPREFIX} != "gcc3"
GCC3_PKGMODIF=	_${GCC3_INSTALLTO_SUBPREFIX}
.    endif
.  endif
BUILDLINK_API_DEPENDS.gcc3-c+=	gcc3${GCC3_PKGMODIF}-c>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc3-c+=	gcc3-c>=3.3.5nb1
BUILDLINK_PKGSRCDIR.gcc3-c?=	../../lang/gcc3-c
BUILDLINK_GCC3_LIBDIRS=		lib
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
BUILDLINK_GCC3_LIBDIRS+=	${GCC3_INSTALLTO_SUBPREFIX}/lib
.  else
BUILDLINK_GCC3_LIBDIRS+=	gcc3/lib
.  endif
BUILDLINK_GCC3_LIBDIRS+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-c}\///}
BUILDLINK_LIBDIRS.gcc3-c+=	${BUILDLINK_GCC3_LIBDIRS}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3-c+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3-c?=	build
.  endif
.endif # GCC3_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc3-c
