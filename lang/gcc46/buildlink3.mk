# $NetBSD: buildlink3.mk,v 1.9 2015/11/25 12:51:16 jperkin Exp $

BUILDLINK_TREE+=	gcc46

.if !defined(GCC46_BUILDLINK3_MK)
GCC46_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc46+=	gcc46>=4.6
BUILDLINK_ABI_DEPENDS.gcc46+=	gcc46>=4.6.0
BUILDLINK_PKGSRCDIR.gcc46=	../../lang/gcc46
BUILDLINK_DEPMETHOD.gcc46?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc46}/gcc46

BUILDLINK_FILES.gcc46=		#empty
BUILDLINK_AUTO_VARS.gcc46=	no

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
DEPENDS+=	{gcc46,gcc46-libs}>=4.6:../../lang/gcc46-libs
ABI_DEPENDS+=	{gcc46,gcc46-libs}>=4.6.0:../../lang/gcc46-libs
.endif

pkgbase := gcc46
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc46:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC46_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc46
