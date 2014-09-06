# $NetBSD: buildlink3.mk,v 1.16 2014/09/06 08:20:28 jperkin Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	gcc

.if !defined(GCC_BUILDLINK3_MK)
GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc+=		gcc>=2.95
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
