# $NetBSD: Makefile,v 1.8 2016/01/22 15:26:25 prlw1 Exp $

DISTNAME=	glmark2-2014.03
PKGREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=glmark2/}
GITHUB_TAG=	acac90b257a14bd14a1492cd442b79dcaa1c13cf

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/glmark2/glmark2
COMMENT=	OpenGL 2.0 and ES 2.0 benchmark
LICENSE=	gnu-gpl-v3 AND modified-bsd

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

USE_TOOLS+=	pkg-config

.include "../../mk/dlopen.buildlink3.mk"
.if empty(BUILTIN_LIB_FOUND.dl:M[yY][eE][sS])
SUBST_CLASSES+=		rmdl
SUBST_STAGE.rmdl=	pre-configure
SUBST_MESSAGE.rmdl=	remove -ldl
SUBST_FILES.rmdl=	src/wscript_build
SUBST_SED.rmdl=		-e "s/, 'dl'//"
.endif

#./waf configure --with-flavors=<drm-gl,drm-glesv2,mir-gl,mir-glesv2,wayland-gl,wayland-glesv2,x11-gl,x11-glesv2> [--data-path=DATA_PATH --prefix=PREFIX]
# drm-gl requires libdrm and "gbm"
do-configure:
	cd ${WRKSRC:Q} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--with-flavors=x11-gl \
			--prefix=${PREFIX} --mandir=${PREFIX}/${PKGMANDIR}

do-build:
	cd ${WRKSRC:Q} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC:Q} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf install \
			--destdir=${DESTDIR}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
