# $NetBSD: Makefile,v 1.11 2012/12/23 18:43:47 dholland Exp $

DISTNAME=		mapit.v1-16
PKGNAME=		dipmap-1.16
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.ugcs.caltech.edu/pub/diplomacy/Sources/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		njohnston@globaltetrahedron.com
HOMEPAGE=		http://www.diplom.org/Online/mapsoftware.html
COMMENT=		Generate postscript maps from results of play-by-email Diplomacy games

MAKE_FILE=		makefile
USE_TOOLS+=		csh:run
WRKSRC=			${WRKDIR}/mapit
INSTALLATION_DIRS=	bin libexec

REPLACE_CSH=		dipmap

post-patch:
	${SED} "s,@PREFIX@,${PREFIX},g" ${WRKSRC}/dipmap > ${WRKSRC}/dipmap.new
	${MV} ${WRKSRC}/dipmap.new ${WRKSRC}/dipmap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dipmap ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mapit
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mapit
	${INSTALL_PROGRAM} ${WRKSRC}/mapit ${DESTDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mapit
	${INSTALL_DATA} ${WRKSRC}/README.maps ${DESTDIR}${PREFIX}/share/doc/mapit
	${INSTALL_DATA} ${WRKSRC}/*.ps ${DESTDIR}${PREFIX}/share/mapit
	${INSTALL_DATA} ${WRKSRC}/*.info ${DESTDIR}${PREFIX}/share/mapit

.include "../../mk/bsd.pkg.mk"
