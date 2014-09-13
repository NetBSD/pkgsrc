# $NetBSD: buildlink3.mk,v 1.5 2014/09/13 01:12:09 obache Exp $

BUILDLINK_TREE+=	gcc48-ccxx

.if !defined(GCC48_CCXX_BUILDLINK3_MK)
GCC48_CCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc48-ccxx+=	gcc48-cc++>=4.8
BUILDLINK_PKGSRCDIR.gcc48-ccxx?=	../../lang/gcc48-cc++

BUILDLINK_GCC48_LIBDIRS=		gcc48/lib
BUILDLINK_LIBDIRS.gcc48-ccxx+=		${BUILDLINK_GCC48_LIBDIRS}
BUILDLINK_DEPMETHOD.gcc48-ccxx?=	build
.endif	# GCC48_CCXX_BUILDLINK3_MK

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
DEPENDS+=	gcc48-libs>=4.8.0:../../lang/gcc48-libs
ABI_DEPENDS+=	gcc48-libs>=4.8.0:../../lang/gcc48-libs
.endif

BUILDLINK_TREE+=	-gcc48-ccxx
