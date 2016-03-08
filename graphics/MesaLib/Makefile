# $NetBSD: Makefile,v 1.122 2016/03/08 21:08:19 tnn Exp $

DISTNAME=	mesa-11.1.2
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${PKGVERSION_NOREV}/
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
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/dri/dri.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/gl.pc.in

CONFIGURE_ARGS+=		--enable-shared-glapi

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
SUBST_SED.wrapper-bug=		-e 's,shared-glapi/libglapi.la,shared-glapi/libglapi_tmp_rename.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi.la,libglapi_impl.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi_tmp_rename.la,libglapi.la,g'

# Replace /etc/drirc with ${PREFIX}/etc/drirc
SUBST_CLASSES+=			drirc
SUBST_STAGE.drirc=		pre-configure
SUBST_MESSAGE.drirc=		Fixing hardcoded /etc/drirc references
SUBST_FILES.drirc+=		src/mesa/drivers/dri/common/xmlconfig.c
SUBST_SED.drirc+=		 -e 's|/etc/|${PREFIX}/etc/|g'

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # as of 10.6.7
BUILD_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
CONFIGURE_ENV+=		ac_cv_prog_PYTHON2=${PYTHONBIN}
.include "../../lang/python/tool.mk"

# On NetBSD < 6 we need to compile with GCC from pkgsrc.
# But GCC from pkgsrc does not add implicit -lc like base GCC does,
# which breaks the build with -Wl,--no-undefined.
# So we piggy back on -lpthread and inject -lc after it.
.if !empty(MACHINE_PLATFORM:MNetBSD-[1-5].*-*)
BUILDLINK_TRANSFORM+=   l:pthread:pthread:c l:m:m:c
.endif

# Handle platforms without exp2
.if !empty(MACHINE_PLATFORM:MNetBSD-[1-5].*-*)
CPPFLAGS+=	-Dexp2\(x\)=exp\(\(x\)\*M_LN2\)
CPPFLAGS+=	-Dexp2f\(x\)=expf\(\(x\)\*M_LN2\)
.endif

# Manual patch for FDO bug 90311. Don't apply if not on Darwin as there could
# be side effects.
.if ${OPSYS} == "Darwin"
pre-configure: ${WRKDIR}/.manual_patch_done
${WRKDIR}/.manual_patch_done:
	cd ${WRKSRC} && ${TOOLS_PATCH} -z .manual -p0 < ${FILESDIR}/patch-manual_fdo90311
	touch ${.TARGET}
.endif

INSTALLATION_DIRS+=	share/examples/MesaLib

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/mesa/drivers/dri/common/drirc ${DESTDIR}${PREFIX}/share/examples/MesaLib

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
