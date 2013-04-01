# $NetBSD: buildlink3.mk,v 1.1 2013/04/01 21:06:15 wiz Exp $

BUILDLINK_TREE+=	gcc48

.if !defined(GCC48_BUILDLINK3_MK)
GCC48_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc48+=	gcc48>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc48+=	gcc48>=4.8.0
BUILDLINK_PKGSRCDIR.gcc48=	../../lang/gcc48
BUILDLINK_DEPMETHOD.gcc48?=	build

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc48=gcc48
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc48}/gcc48

BUILDLINK_FILES.gcc48=		#empty
BUILDLINK_AUTO_VARS.gcc48=	no

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
DEPENDS+=	{gcc, gcc48-libs}>=${_GCC_REQD}:../../lang/gcc48-libs
ABI_DEPENDS+=	{gcc,gcc48-libs}>=4.8.0:../../lang/gcc48-libs
.endif

pkgbase := gcc48
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc48:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC48_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc48
