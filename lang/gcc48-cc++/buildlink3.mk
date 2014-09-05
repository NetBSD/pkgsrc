# $NetBSD: buildlink3.mk,v 1.3 2014/09/05 21:41:45 jperkin Exp $

BUILDLINK_TREE+=	gcc48-cc++

.if !defined(GCC48_CC++_BUILDLINK3_MK)
GCC48_CC++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc48-cc+++=	gcc48-cc++>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc48-cc++?=	../../lang/gcc48-cc++

BUILDLINK_GCC48_LIBDIRS=		gcc48/lib
BUILDLINK_LIBDIRS.gcc48-cc+++=		${BUILDLINK_GCC48_LIBDIRS}
BUILDLINK_DEPMETHOD.gcc48-cc++?=	build
.endif	# GCC48_CC++_BUILDLINK3_MK

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
DEPENDS+=	gcc48-libs>=4.8.0:../../lang/gcc48-libs
ABI_DEPENDS+=	gcc48-libs>=4.8.0:../../lang/gcc48-libs
.endif

BUILDLINK_TREE+=	-gcc48-cc++
