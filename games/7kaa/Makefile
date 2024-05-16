# $NetBSD: Makefile,v 1.36 2024/05/16 06:14:52 wiz Exp $

DISTNAME=	7kaa-2.15.6
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=skfans/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://7kfans.com/
COMMENT=	Seven Kingdoms: Ancient Adversaries
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++11

LDFLAGS+=	${BUILDLINK_LDADD.gettext}

CONFIGURE_ARGS+=	--disable-sdltest

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

# https://www.7kfans.com/forums/viewtopic.php?f=13&t=1150&p=8652
# (bug report; requires login)
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

post-extract:
	${PREFIX}/bin/icotool -x -i 1 ${WRKSRC}/src/7k.ico -o ${WRKDIR}/7kaa.png

post-install:
	${INSTALL_DATA} ${FILESDIR}/7kaa.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/7kaa.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
