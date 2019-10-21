# $NetBSD: Makefile,v 1.172 2019/10/21 20:47:55 nia Exp $

DISTNAME=	mesa-19.2.1
PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.mesa3d.org/
COMMENT=	Open source OpenGL implementation
LICENSE=	mit

USE_TOOLS+=	bison flex pkg-config xgettext
USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Fixing Python binary name
SUBST_FILES.py+=	meson.build
SUBST_VARS.py+=		PYTHONBIN

CFLAGS.SunOS+=		-D__EXTENSIONS__ -D_POSIX_PTHREAD_SEMANTICS
CXXFLAGS.SunOS+=	-Drestrict=__restrict__
LDFLAGS.SunOS+=		-lsocket -lnsl

# Some of these get appended in options.mk.
DRI_DRIVERS=		#
GALLIUM_DRIVERS=	swrast
VULKAN_DRIVERS=		#
MESA_PLATFORMS=		surfaceless

.include "../../mk/compiler.mk"
.include "features.mk"
.include "options.mk"

PLIST_SUBST+=	GLVER="1.2.0"

# classic DRI drivers
PLIST_VARS+=		i915 i965 r100 r200 nouveau_dri

# Gallium drivers
PLIST_VARS+=		r300 svga nouveau vc4 lima panfrost

# other features
PLIST_VARS+=		egl gbm vaapi xatracker

.if ${MESALIB_SUPPORTS_DRI} == "yes"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.81
.include "../../x11/libdrm/buildlink3.mk"
MESA_PLATFORMS+=	drm
MESON_ARGS+=		-Degl=true
MESON_ARGS+=		-Dgbm=true
MESON_ARGS+=		-Dgallium-xa=true
PLIST.egl=		yes
PLIST.gbm=		yes
PLIST.xatracker=	yes
.  include "../../multimedia/libva/available.mk"
.  if ${VAAPI_AVAILABLE} == "yes"
MESON_ARGS+=		-Dgallium-va=true
PLIST.vaapi=		yes
.    include "../../multimedia/libva/buildlink3.mk"
.  else
MESON_ARGS+=		-Dgallium-va=false
.  endif
.  if !empty(MACHINE_ARCH:M*arm*) || \
      ${MACHINE_ARCH} == "aarch64"
# ARM Mali Utgard
GALLIUM_DRIVERS+=	lima
PLIST.lima=		yes
# ARM Mali Midgard, Bifrost
GALLIUM_DRIVERS+=	panfrost
PLIST.panfrost=		yes
# Vivante GCxxx
#GALLIUM_DRIVERS+=	etnaviv
#PLIST.etnaviv=		yes
# Qualcomm Snapdragon
#GALLIUM_DRIVERS+=	freedreno
#PLIST.freedreno=	yes
# Broadcom VideoCore 4
GALLIUM_DRIVERS+=	vc4
PLIST.vc4=		yes
.  endif
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
GALLIUM_DRIVERS+=	svga
DRI_DRIVERS+=		i915 i965
PLIST.svga=		yes
PLIST.i915=		yes
PLIST.i965=		yes
.  endif
# FreeBSD lacks nouveau support (there are official binaries from Nvidia)
.  if ${OPSYS} != "FreeBSD"
PLIST.nouveau=		yes
PLIST.nouveau_dri=	yes
GALLIUM_DRIVERS+=	nouveau
DRI_DRIVERS+=		nouveau
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
.endif

MESON_ARGS+=	-Dgles1=true
MESON_ARGS+=	-Dgles2=true
MESON_ARGS+=	-Dosmesa=gallium
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

OWN_DIRS=	${PKG_SYSCONFDIR}/drirc.d
CONF_FILES+=	${EGDIR}/00-mesa-defaults.conf \
		${PKG_SYSCONFDIR}/drirc.d/00-mesa-defaults.conf

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

pre-configure:
	${TOUCH} ${WRKSRC}/src/glx/apple_dummy.cpp

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/drirc.d/00-mesa-defaults.conf ${DESTDIR}${EGDIR}

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
