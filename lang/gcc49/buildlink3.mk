# $NetBSD: buildlink3.mk,v 1.2 2014/09/06 08:20:29 jperkin Exp $

BUILDLINK_TREE+=	gcc49

.if !defined(GCC49_BUILDLINK3_MK)
GCC49_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc49+=	gcc49>=4.9
BUILDLINK_ABI_DEPENDS.gcc49+=	gcc49>=4.9.1
BUILDLINK_PKGSRCDIR.gcc49=	../../lang/gcc49
BUILDLINK_DEPMETHOD.gcc49?=	build

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc49=gcc49
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc49}/gcc49

BUILDLINK_FILES.gcc49=		#empty
BUILDLINK_AUTO_VARS.gcc49=	no

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
DEPENDS+=	{gcc49,gcc49-libs}>=4.9:../../lang/gcc49-libs
.endif

pkgbase := gcc49
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc49:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC49_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc49
