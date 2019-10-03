# $NetBSD: Makefile,v 1.167 2019/10/03 15:50:06 nia Exp $

DISTNAME=	mesa-19.1.6
PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mesa3d.org/
COMMENT=	Open source OpenGL implementation
LICENSE=	mit

USE_TOOLS+=	bison flex pkg-config xgettext
USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/egl/main/egl.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/d3dadapter9/d3d.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/xa/xatracker.pc.in
PKGCONFIG_OVERRIDE+=	src/gbm/main/gbm.pc.in
PKGCONFIG_OVERRIDE+=	src/glx/windows/windowsdriproto.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es1api/glesv1_cm.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es2api/glesv2.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/dri/dri.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/gl.pc.in

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

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "options.mk"

PLIST_SUBST+=	GLVER="1.2.0"

# classic DRI drivers
PLIST_VARS+=		i915 i965 r100 r200 nouveau_dri

# Gallium drivers
PLIST_VARS+=		r300 svga nouveau vc4 lima panfrost

# other features
PLIST_VARS+=		egl gbm vaapi xatracker

.if ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"
.include "../../x11/libdrm/buildlink3.mk"
MESA_PLATFORMS+=	drm
.  if ${OPSYS} != "SunOS"
MESON_ARGS+=		-Degl=true
MESON_ARGS+=		-Dgbm=true
MESON_ARGS+=		-Dgallium-xa=true
PLIST.egl=		yes
PLIST.gbm=		yes
PLIST.xatracker=	yes
.  else
MESON_ARGS+=		-Degl=false
MESON_ARGS+=		-Dgbm=false
.  endif
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
.endif # ${OPSYS} != "Darwin" && ${OPSYS} != "Cygwin"

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

# https://gitlab.freedesktop.org/mesa/mesa/merge_requests/1854
BUILDLINK_TRANSFORM+=		rm:-Werror=return-type

# https://gitlab.freedesktop.org/mesa/mesa/merge_requests/1853
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--build-id=sha1

# Work around Xorg segfaulting in radeon driver due to wrong alloca being used
CFLAGS.NetBSD+=		-Dalloca=__builtin_alloca
CXXFLAGS.NetBSD+=	-Dalloca=__builtin_alloca

PYTHON_FOR_BUILD_ONLY=	yes

TOOL_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako

# needed to build vulkan support
TOOL_DEPENDS+=		${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

# LLVM detection
TOOL_DEPENDS+=		${PYPKGPREFIX}-meson>=0.51.1nb3:../../devel/py-meson

EGDIR=		${PREFIX}/share/examples/mesa

OWN_DIRS=	${PKG_SYSCONFDIR}/drirc.d
CONF_FILES+=	${EGDIR}/00-mesa-defaults.conf \
		${PKG_SYSCONFDIR}/drirc.d/00-mesa-defaults.conf

INSTALLATION_DIRS+=	${EGDIR}

pre-configure:
	touch ${WRKSRC}/src/glx/apple_dummy.cpp

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/drirc.d/00-mesa-defaults.conf ${DESTDIR}${EGDIR}

.include "../../devel/py-meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
