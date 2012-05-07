# $NetBSD: buildlink3.mk,v 1.15 2012/05/07 01:53:39 dholland Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	gcc

.if !defined(GCC_BUILDLINK3_MK)
GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc+=		gcc>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc+=	gcc>=2.95.3nb7
BUILDLINK_PKGSRCDIR.gcc?=	../../lang/gcc
BUILDLINK_LIBDIRS.gcc?=		\
	${_GCC_PREFIX:S/^${BUILDLINK_PREFIX.gcc}\///}lib \
	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc?=	build
.  endif
.endif # GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc
