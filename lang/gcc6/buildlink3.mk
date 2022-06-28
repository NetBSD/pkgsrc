# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:34:11 wiz Exp $

BUILDLINK_TREE+=	gcc6

.if !defined(GCC6_BUILDLINK3_MK)
GCC6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc6+=	gcc6>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc6+=	gcc6>=6.5.0nb8
BUILDLINK_PKGSRCDIR.gcc6=	../../lang/gcc6
BUILDLINK_DEPMETHOD.gcc6?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc6}/gcc6

BUILDLINK_FILES.gcc6=		#empty
BUILDLINK_AUTO_VARS.gcc6=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc6, gcc6-libs}>=${_GCC_REQD}:../../lang/gcc6-libs
#ABI_DEPENDS+=	{gcc6,gcc6-libs}>=6.0:../../lang/gcc6-libs
#.endif

pkgbase := gcc6
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc6:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC6_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc6
