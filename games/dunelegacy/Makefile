# $NetBSD: Makefile,v 1.5 2020/03/20 11:57:40 nia Exp $

DISTNAME=		dunelegacy-0.96.4-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dunelegacy/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dunelegacy.sourceforge.net/
COMMENT=		Open source Dune 2 clone
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps

post-install:
	${INSTALL_DATA} ${WRKSRC}/dunelegacy.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/dunelegacy.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/dunelegacy.png
	${INSTALL_DATA} ${WRKSRC}/dunelegacy-128x128.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/128x128/apps/dunelegacy.png
	${INSTALL_DATA} ${WRKSRC}/dunelegacy.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/dunelegacy.svg

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
