# $NetBSD: Makefile,v 1.157 2019/08/28 09:09:15 nia Exp $

DISTNAME=	mesa-19.1.5
PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
CATEGORIES=	graphics x11
MASTER_SITES=	https://mesa.freedesktop.org/archive/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mesa3d.org/
COMMENT=	Open source OpenGL implementation
LICENSE=	mit

USE_TOOLS+=	bison flex pkg-config
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

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "options.mk"

.if ${MACHINE_ARCH} == "i386"
MESON_ARGS+=	-Dglx-read-only-text=true
.endif

MESON_ARGS+=	-Dshared-glapi=true

CPPFLAGS+=	-DHAVE_NOATEXIT
CPPFLAGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}

BUILDLINK_TRANSFORM+=	rm:-Werror=return-type

# Work around Xorg segfaulting in radeon driver due to wrong alloca being used
CFLAGS.NetBSD+=		-Dalloca=__builtin_alloca
CXXFLAGS.NetBSD+=	-Dalloca=__builtin_alloca

PYTHON_FOR_BUILD_ONLY=	yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
# needed to build vulkan support
BUILD_DEPENDS+=		${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

# LLVM detection
TOOL_DEPENDS+=		${PYPKGPREFIX}-meson>=0.51.1nb3:../../devel/py-meson

EGDIR=			${PREFIX}/share/examples/mesa
INSTALLATION_DIRS+=	${EGDIR}
OWN_DIRS=		${PKG_SYSCONFDIR}/drirc.d
CONF_FILES+=		${EGDIR}/00-mesa-defaults.conf \
			${PKG_SYSCONFDIR}/drirc.d/00-mesa-defaults.conf

pre-configure:
	touch ${WRKSRC}/src/glx/apple_dummy.cpp

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/drirc.d/00-mesa-defaults.conf ${DESTDIR}${EGDIR}

.include "../../devel/py-meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
