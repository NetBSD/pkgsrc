# $NetBSD: Makefile,v 1.1 2015/02/28 23:09:27 prlw1 Exp $

GHCOMMIT=	499aa81a68fb4c8aac1c80f0d6a4cce05941c4cc
DISTNAME=	${GHCOMMIT}
PKGNAME=	glmark2-2014.03
CATEGORIES=	benchmarks
MASTER_SITES=	https://github.com/glmark2/glmark2/archive/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/glmark2/glmark2
COMMENT=	OpenGL 2.0 and ES 2.0 benchmark
LICENSE=	gnu-gpl-v3 AND modified-bsd

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

WRKSRC=		${WRKDIR}/glmark2-${GHCOMMIT}

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
