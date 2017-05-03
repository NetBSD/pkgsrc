# $NetBSD: buildlink3.mk,v 1.2 2017/05/03 00:54:59 maya Exp $

BUILDLINK_TREE+=	gcc7

.if !defined(GCC7_BUILDLINK3_MK)
GCC6SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc7+=	gcc7>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc7+=	gcc7>=7.0
BUILDLINK_PKGSRCDIR.gcc7=	../../lang/gcc7
BUILDLINK_DEPMETHOD.gcc7?=	build

BUILDLINK_FILES.gcc7=		#empty
BUILDLINK_AUTO_VARS.gcc7=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc7, gcc7-libs}>=${_GCC_REQD}:../../lang/gcc7-libs
#ABI_DEPENDS+=	{gcc7,gcc7-libs}>=7.0:../../lang/gcc7-libs
#.endif

pkgbase := gcc7
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # gcc7_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc7
