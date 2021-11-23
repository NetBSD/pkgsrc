# $NetBSD: Makefile,v 1.1 2021/11/23 11:45:47 nia Exp $

DISTNAME=	cutoggvorbis-0.2
CATEGORIES=	audio
MASTER_SITES=	https://puchalla-online.de/cutoggvorbis/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.puchalla-online.de/cutoggvorbis/cutoggvorbis.html
COMMENT=	Command line editor for cutting Ogg Vorbis without quality loss
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gzip

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/cutoggvorbis

pre-build:
	cp ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cutoggvorbis ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cutoggvorbis.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/Changelog ${DESTDIR}${PREFIX}/share/cutoggvorbis
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/cutoggvorbis
	${INSTALL_DATA} ${WRKSRC}/EXITCODES ${DESTDIR}${PREFIX}/share/cutoggvorbis
	${INSTALL_DATA} ${WRKSRC}/USAGE ${DESTDIR}${PREFIX}/share/cutoggvorbis

.include "../../mk/bsd.pkg.mk"
