# $NetBSD: Makefile,v 1.10 2022/08/11 05:08:25 gutteridge Exp $

DISTNAME=	endless-sky-0.9.14
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=endless-sky/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://endless-sky.github.io/
COMMENT=	Side-scrolling space trading game
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v4.0 AND cc-by-sa-v3.0

USE_LANGUAGES=	c++11
USE_TOOLS+=	pax
BUILD_DIRS+=	. source

post-extract:
	${CP} ${FILESDIR}/Makefile.top ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/Makefile.source ${WRKSRC}/source/Makefile
	${CHMOD} -R go+rX ${WRKSRC}/data
	${CHMOD} -R go+rX ${WRKSRC}/images
	${CHMOD} -R go+rX ${WRKSRC}/sounds

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
