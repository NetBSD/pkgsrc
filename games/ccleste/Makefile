# $NetBSD: Makefile,v 1.1 2024/05/07 08:40:19 nia Exp $

DISTNAME=	ccleste-1.4.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=lemon32767/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/lemon32767/ccleste
COMMENT=	Portable version of the Celeste Classic 2D platform game
#LICENSE=	# freeware

USE_TOOLS+=	gmake pax

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/ccleste/data
INSTALLATION_DIRS+=	share/pixmaps

pre-configure:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/ccleste.sh > \
		${WRKDIR}/ccleste.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ccleste.sh \
		${DESTDIR}${PREFIX}/bin/ccleste
	${INSTALL_PROGRAM} ${WRKSRC}/ccleste \
		${DESTDIR}${PREFIX}/libexec/ccleste
	${INSTALL_DATA} ${FILESDIR}/ccleste.desktop \
		${DESTDIR}${PREFIX}/share/applications/ccleste.desktop
	${INSTALL_DATA} ${WRKSRC}/icon.png \
		${DESTDIR}${PREFIX}/share/pixmaps/ccleste.png
	cd ${WRKSRC}/data && ${PAX} -rw -pp . \
		${DESTDIR}${PREFIX}/share/ccleste/data

.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
