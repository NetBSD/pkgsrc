# $NetBSD: Makefile,v 1.2 2019/07/01 04:08:09 ryoon Exp $

DISTNAME=	7kaa-2.15.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=the3dfxdude/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://7kfans.com/
COMMENT=	Seven Kingdoms: Ancient Adversaries
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++11
GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	pkg-config

# C++11
GCC_REQD+=	4.6

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps

post-extract:
	${PREFIX}/bin/convert ${WRKSRC}/src/7k.ico ${WRKDIR}/7kaa.png

post-install:
	${INSTALL_DATA} ${FILESDIR}/7kaa.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/7kaa.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
