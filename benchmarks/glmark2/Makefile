# $NetBSD: Makefile,v 1.6 2015/04/25 14:20:26 tnn Exp $

DISTNAME=	glmark2-2014.03
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=glmark2/}
GITHUB_TAG=	499aa81a68fb4c8aac1c80f0d6a4cce05941c4cc

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/glmark2/glmark2
COMMENT=	OpenGL 2.0 and ES 2.0 benchmark
LICENSE=	gnu-gpl-v3 AND modified-bsd

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

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
