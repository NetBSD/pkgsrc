# $NetBSD: buildlink3.mk,v 1.2 2015/11/25 12:51:17 jperkin Exp $

BUILDLINK_TREE+=	gcc5

.if !defined(GCC5_BUILDLINK3_MK)
GCC5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc5+=	gcc5>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc5+=	gcc5>=5.1
BUILDLINK_PKGSRCDIR.gcc5=	../../lang/gcc5
BUILDLINK_DEPMETHOD.gcc5?=	build

BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc5}/gcc5

BUILDLINK_FILES.gcc5=		#empty
BUILDLINK_AUTO_VARS.gcc5=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc5, gcc5-libs}>=${_GCC_REQD}:../../lang/gcc5-libs
#ABI_DEPENDS+=	{gcc5,gcc5-libs}>=5.1.0:../../lang/gcc5-libs
#.endif

pkgbase := gcc5
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc5:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC5_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc5
