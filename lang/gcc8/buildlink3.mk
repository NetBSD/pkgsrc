# $NetBSD: buildlink3.mk,v 1.3 2020/04/08 06:39:57 wiz Exp $

BUILDLINK_TREE+=	gcc8

.if !defined(GCC8_BUILDLINK3_MK)
GCC8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc8+=	gcc8>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc8+=	gcc8>=8.0
BUILDLINK_PKGSRCDIR.gcc8=	../../lang/gcc8
BUILDLINK_DEPMETHOD.gcc8?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc8}/gcc8

BUILDLINK_FILES.gcc8=		#empty
BUILDLINK_AUTO_VARS.gcc8=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc8, gcc8-libs}>=${_GCC_REQD}:../../lang/gcc8-libs
#ABI_DEPENDS+=	{gcc8,gcc8-libs}>=8.0:../../lang/gcc8-libs
#.endif

pkgbase := gcc8
.include "../../mk/pkg-build-options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC8_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc8
