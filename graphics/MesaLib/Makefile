# $NetBSD: Makefile,v 1.100 2015/04/25 11:19:18 tnn Exp $

DISTNAME=	mesa-10.5.3
PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/10.5.3/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	The Mesa 3D Graphics Library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes

GCC_REQD+=	4.2

PKGCONFIG_OVERRIDE+=	src/egl/main/egl.pc.in
PKGCONFIG_OVERRIDE+=	src/egl/wayland/wayland-egl/wayland-egl.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/d3dadapter9/d3d.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/xa/xatracker.pc.in
PKGCONFIG_OVERRIDE+=	src/gbm/main/gbm.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es1api/glesv1_cm.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es2api/glesv2.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/vgapi/vg.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/dri/dri.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/gl.pc.in

# Work around a buildlink and/or libtool bug:
# In the libtool install/relink stage, if we want to link with two static
# archives named libglapi.la but in different directories, bad things happen.
SUBST_CLASSES+=			wrapper-bug
SUBST_STAGE.wrapper-bug=	pre-configure
SUBST_MESSAGE.wrapper-bug=	Renaming glapi-shared/libglapi in Makefiles
SUBST_FILES.wrapper-bug=	src/gbm/Makefile.in
SUBST_FILES.wrapper-bug+=	src/glx/Makefile.in
SUBST_FILES.wrapper-bug+=	src/mapi/Makefile.in
SUBST_FILES.wrapper-bug+=	src/mesa/drivers/x11/Makefile.in
SUBST_SED.wrapper-bug=		-e 's,shared-glapi/libglapi.la,shared-glapi/libglapi_shared.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi.la,libglapi_static.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi_shared.la,libglapi.la,g'

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "options.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
SUBST_CLASSES+=		tr1
SUBST_STAGE.tr1=	pre-configure
SUBST_MESSAGE.tr1=	Fixing TR1 C++ namespace
SUBST_FILES.tr1=	src/gallium/drivers/nouveau/codegen/*.h
SUBST_FILES.tr1+=	src/gallium/drivers/nouveau/codegen/*.cpp
SUBST_SED.tr1=		-e 's,std::tr1::,std::,g'
SUBST_SED.tr1+=		-e 's,include <tr1/,include <,g'
.endif

PYTHON_FOR_BUILD_ONLY=	yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
.include "../../lang/python/tool.mk"

# On NetBSD < 6 we need to compile with GCC from pkgsrc.
# But GCC from pkgsrc does not add implicit -lc like base GCC does,
# which breaks the build with -Wl,--no-undefined.
# So we piggy back on -lpthread and inject -lc after it.
.if !empty(MACHINE_PLATFORM:MNetBSD-[1-5].*-*)
BUILDLINK_TRANSFORM+=   l:pthread:pthread:c
.endif

# Handle platforms without exp2
.if !empty(MACHINE_PLATFORM:MNetBSD-[1-5].*-*)
CPPFLAGS+=	-Dexp2\(x\)=exp\(\(x\)\*M_LN2\)
CPPFLAGS+=	-Dexp2f\(x\)=expf\(\(x\)\*M_LN2\)
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
