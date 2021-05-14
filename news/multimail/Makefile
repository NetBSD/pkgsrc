# $NetBSD: Makefile,v 1.2 2021/05/14 12:15:02 nia Exp $

DISTNAME=	mmail-0.52
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=multimail/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://multimail.sourceforge.io/
COMMENT=	Offline mail reader for Blue Wave, QWK, OMEN, SOUP and OPX
LICENSE=	gnu-gpl-v3

DEPENDS+=	zip-[0-9]*:../../archivers/zip
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
