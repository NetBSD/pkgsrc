# $NetBSD: Makefile,v 1.1 2020/07/26 05:21:20 dholland Exp $

GITHUB_PROJECT=	endless-sky
GITHUB_TAG=	v0.9.12
DISTNAME=	v0.9.12
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=endless-sky/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/endless-sky/endless-sky/
COMMENT=	Side-scrolling space trading game
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v4.0 AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/endless-sky-0.9.12
USE_LANGUAGES=	c++11
ICON_THEMES=	yes
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
#.include "../../graphics/libjpeg-turbo.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
