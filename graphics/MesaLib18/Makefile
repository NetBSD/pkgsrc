# $NetBSD: Makefile,v 1.4 2018/11/21 07:15:22 maya Exp $

DISTNAME=	mesa-18.2.0
PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/
# MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mesa3d.org/
COMMENT=	The Mesa 3D Graphics Library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison pkg-config gmake flex
USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/egl/main/egl.pc.in
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
SUBST_FILES.wrapper-bug+=	src/mesa/drivers/osmesa/Makefile.in
SUBST_SED.wrapper-bug=		-e 's,shared-glapi/libglapi.la,shared-glapi/libglapi_tmp_rename.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi.la,libglapi_impl.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi_tmp_rename.la,libglapi.la,g'

# Replace /etc/drirc with ${PREFIX}/etc/drirc
SUBST_CLASSES+=			drirc
SUBST_STAGE.drirc=		pre-configure
SUBST_MESSAGE.drirc=		Fixing hardcoded /etc/drirc references
SUBST_FILES.drirc+=		src/util/xmlconfig.c
SUBST_SED.drirc+=		 -e 's|/etc|${PREFIX}/etc|g'

CFLAGS.SunOS+=		-D__EXTENSIONS__ -D_POSIX_PTHREAD_SEMANTICS
CXXFLAGS.SunOS+=	-Drestrict=__restrict__
LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "options.mk"

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-glx-read-only-text
.endif

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 11.2.2
BUILD_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
CONFIGURE_ENV+=		ac_cv_prog_PYTHON2=${PYTHONBIN}
.include "../../lang/python/tool.mk"

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
	${INSTALL_DATA} ${WRKSRC}/src/util/drirc ${DESTDIR}${PREFIX}/share/examples/MesaLib

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
