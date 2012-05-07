# $NetBSD: buildlink3.mk,v 1.2 2012/05/07 01:53:41 dholland Exp $

BUILDLINK_TREE+=	gcc47

.if !defined(GCC47_BUILDLINK3_MK)
GCC47_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc47+=	gcc47>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc47+=	gcc47>=4.7.0
BUILDLINK_PKGSRCDIR.gcc47?=	../../lang/gcc47

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc47=gcc47
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc47}/gcc47

BUILDLINK_FILES.gcc47=		#empty
BUILDLINK_AUTO_VARS.gcc47=	no

# When not using the GNU linker, gcc will always link shared libraries
# against the shared version of libgcc. Always enable _USE_GCC_SHILB on
# platforms that don't use the GNU linker, such as SunOS.
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
_USE_GCC_SHLIB= yes
.endif

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc47+=	full
.else
BUILDLINK_DEPMETHOD.gcc47?=	build
.endif

pkgbase := gcc47
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc47:Mgcc-java) || \
    !empty(PKG_BUILD_OPTIONS.gcc47:Mgcc-go)
.include "../../mk/pthread.buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.gcc47:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif

.endif # GCC46_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc47
