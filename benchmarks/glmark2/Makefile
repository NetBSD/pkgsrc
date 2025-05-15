# $NetBSD: Makefile,v 1.25 2025/05/15 11:57:39 rjs Exp $

DISTNAME=	glmark2-2023.01
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=glmark2/}
PKGREVISION=	4

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/glmark2/glmark2
COMMENT=	OpenGL 2.0 and ES 2.0 benchmark
LICENSE=	gnu-gpl-v3 AND modified-bsd

USE_LANGUAGES=	c c++14

USE_TOOLS+=	pkg-config

.include "../../mk/dlopen.buildlink3.mk"
.if ${BUILTIN_LIB_FOUND.dl:U:tl} != yes
SUBST_CLASSES+=		rmdl
SUBST_STAGE.rmdl=	pre-configure
SUBST_MESSAGE.rmdl=	remove -ldl
SUBST_FILES.rmdl=	src/wscript_build
SUBST_SED.rmdl=		-e "s/, 'dl'//"
.endif

LDFLAGS+=	${PTHREAD_LDFLAGS}
LIBS+=		${PTHREAD_LIBS}

MESON_ARGS+=	-Dflavors=x11-gl

.include "../../devel/meson/build.mk"
.include "../../devel/cmake/build.mk"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
