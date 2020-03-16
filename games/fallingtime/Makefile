# $NetBSD: Makefile,v 1.4 2020/03/16 10:10:59 nia Exp $

DISTNAME=	fallingtime-1.0.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=cxong/}
GITHUB_PROJECT=	FallingTime

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/cxong/FallingTime
COMMENT=	Arcade game inspired by Fall Down
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99 c++

CMAKE_ARGS+=	-DINSTALL_PREFIX=${PREFIX}/libexec
CMAKE_ARGS+=	-DINSTALL_DATA_PREFIX=${PREFIX}/share/fallingtime

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
	    ${FILESDIR}/fallingtime.template > ${WRKDIR}/fallingtime

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fallingtime \
	    ${DESTDIR}${PREFIX}/bin/fallingtime
	${INSTALL_DATA} ${WRKSRC}/pkg/linux/io.github.cxong.fallingtime.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/fallingtime.desktop
	${INSTALL_DATA} ${WRKSRC}/pkg/linux/fallingtime.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/fallingtime.png

.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
