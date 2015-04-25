# $NetBSD: buildlink3.mk,v 1.1 2015/04/25 10:32:07 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	gcc2

.if !defined(GCC2_BUILDLINK3_MK)
GCC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc2+=	gcc2>=2.95
BUILDLINK_ABI_DEPENDS.gcc2+=	gcc2>=2.95.3nb7
BUILDLINK_PKGSRCDIR.gcc2?=	../../lang/gcc2
BUILDLINK_LIBDIRS.gcc2?=		\
	${_GCC_PREFIX:S/^${BUILDLINK_PREFIX.gcc2}\///}lib \
	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc2}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc2+=	full
.  else
BUILDLINK_DEPMETHOD.gcc2?=	build
.  endif
.endif # GCC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc2
