# $NetBSD: Makefile,v 1.203 2022/08/06 16:48:06 he Exp $

DISTNAME=	mesa-21.3.9
PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.mesa3d.org/
COMMENT=	Open source OpenGL implementation
LICENSE=	mit

USE_TOOLS+=	bison flex pkg-config xgettext
USE_LANGUAGES=	c99 c++14

# ERROR: C++ Compiler does not support -std=c++14
GCC_REQD+=	5

USE_FEATURES+=	strnlen

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS
CXXFLAGS.SunOS+=	-Drestrict=__restrict__
LDFLAGS.SunOS+=		-lsocket -lnsl

# Some of these get appended in options.mk.
DRI_DRIVERS=		#
GALLIUM_DRIVERS=	swrast
VULKAN_DRIVERS=		#
MESA_PLATFORMS=		#

.include "../../mk/compiler.mk"
.include "features.mk"
.include "options.mk"

PLIST_SUBST+=	GLVER="1.2.0"
PLIST_SUBST+=	MACHINE_ARCH=${MACHINE_ARCH}

# classic DRI drivers
PLIST_VARS+=		i830 i915 i965 r100 r200 nouveau_dri

# Gallium drivers
PLIST_VARS+=		r300 svga nouveau iris

# other features
PLIST_VARS+=		arm kms vaapi xa

.if ${MESALIB_SUPPORTS_DRI} == "yes"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.100
.include "../../x11/libdrm/buildlink3.mk"
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
.    include "../../sysutils/libpciaccess/buildlink3.mk"
.  endif
MESON_ARGS+=		-Degl=true
MESON_ARGS+=		-Dgbm=true
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" ||	\
      ${MACHINE_ARCH:M*arm*} || ${MACHINE_CPU} == "aarch64"
# XA state tracker requires at least one of the following gallium drivers:
# nouveau, freedreno, i915, svga
MESON_ARGS+=		-Dgallium-xa=enabled
PLIST.xa=		yes
.  else
MESON_ARGS+=		-Dgallium-xa=disabled
.  endif
.  if ${X11_TYPE} == "native" && !exists(${X11BASE}/include/xcb/dri3.h)
MESON_ARGS+=		-Ddri3=false
.  endif
PLIST.kms=		yes
.  if ${MACHINE_ARCH:M*arm*} || \
      ${MACHINE_CPU} == "aarch64"
GALLIUM_DRIVERS+=	freedreno vc4 etnaviv tegra panfrost lima
PLIST.arm=		yes
.  endif
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
GALLIUM_DRIVERS+=	svga iris
DRI_DRIVERS+=		i915 i965
PLIST.svga=		yes
PLIST.i830=		yes
PLIST.i915=		yes
PLIST.i965=		yes
PLIST.iris=		yes
.  endif
# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.  if ${OPSYS} != "FreeBSD"
.    if empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
# nouveau not available on this platform
PLIST.nouveau=		yes
PLIST.nouveau_dri=	yes
GALLIUM_DRIVERS+=	nouveau
DRI_DRIVERS+=		nouveau
.    endif
.  endif
.  if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
# qemu Linux guest driver
# XXX test this
#GALLIUM_DRIVERS+=	virgl
#PLIST.virgl=		yes
.  endif
# theoretically cross platform PCI drivers
.  if empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) && \
      empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)
DRI_DRIVERS+=		r100 r200
GALLIUM_DRIVERS+=	r300
PLIST.r100=		yes
PLIST.r200=		yes
PLIST.r300=		yes
.  endif
.  include "../../multimedia/libva/available.mk"
.  if ${VAAPI_AVAILABLE} == "yes" && \
      !(empty(GALLIUM_DRIVERS:Mr600) && empty(GALLIUM_DRIVERS:Mradeonsi) && \
        empty(GALLIUM_DRIVERS:Mnouveau))
MESON_ARGS+=		-Dgallium-va=enabled
PLIST.vaapi=		yes
BUILDLINK_API_DEPENDS.libva+=	libva>=2.13.0
.    include "../../multimedia/libva/buildlink3.mk"
.  else
MESON_ARGS+=		-Dgallium-va=disabled
.  endif
.else
MESON_ARGS+=		-Degl=false
MESON_ARGS+=		-Dgbm=false
.endif # ${MESALIB_SUPPORTS_DRI} == "yes"

MESON_ARGS+=	-Dgallium-drivers=${GALLIUM_DRIVERS:ts,}
MESON_ARGS+=	-Ddri-drivers=${DRI_DRIVERS:ts,}
MESON_ARGS+=	-Dvulkan-drivers=${VULKAN_DRIVERS:ts,}
MESON_ARGS+=	-Dplatforms=${MESA_PLATFORMS:ts,}

.if ${MACHINE_ARCH} == "i386"
MESON_ARGS+=	-Dglx-read-only-text=true
CFLAGS+=	-march=i586
CXXFLAGS+=	-march=i586
.endif

MESON_ARGS+=	-Dgles1=true
MESON_ARGS+=	-Dgles2=true
MESON_ARGS+=	-Dosmesa=true
MESON_ARGS+=	-Dshared-glapi=true
MESON_ARGS+=	-Dgallium-xvmc=false

CPPFLAGS+=	-DHAVE_NOATEXIT
CPPFLAGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}

TOOL_DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako

# needed to build vulkan support
TOOL_DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

BUILDLINK_TRANSFORM+=		rm:-Werror=incompatible-pointer-types

# https://gitlab.freedesktop.org/mesa/mesa/merge_requests/1854
BUILDLINK_TRANSFORM+=		rm:-Werror=return-type

# ../src/intel/perf/gen_perf.c:426:7: error: %m is only allowed in syslog(3) like functions
BUILDLINK_TRANSFORM+=		rm:-Werror=format
BUILDLINK_TRANSFORM+=		rm:-Wformat-security

# https://gitlab.freedesktop.org/mesa/mesa/merge_requests/1853
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--build-id=sha1

# Work around Xorg segfaulting in radeon driver due to wrong alloca being used
CFLAGS.NetBSD+=		-Dalloca=__builtin_alloca
CXXFLAGS.NetBSD+=	-Dalloca=__builtin_alloca

EGDIR=		${PREFIX}/share/examples/mesa

CONF_FILES+=	${EGDIR}/00-mesa-defaults.conf ${PKG_SYSCONFDIR}/drirc

INSTALLATION_DIRS+=	${EGDIR}

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/glesv1_cm.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/glesv2.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/dri.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/gbm.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/egl.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/osmesa.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/xatracker.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/gl.pc

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/drirc.d/00-mesa-defaults.conf ${DESTDIR}${EGDIR}
.if ${OPSYS} == "Darwin"
	install_name_tool -id ${PREFIX}/lib/dri/swrast_dri.so \
	    ${DESTDIR}${PREFIX}/lib/dri/swrast_dri.so
.endif

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
