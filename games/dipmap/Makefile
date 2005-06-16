# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:54 jlam Exp $

DISTNAME=		mapit.v1-16
PKGNAME=		dipmap-1.16
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.ugcs.caltech.edu/pub/diplomacy/Sources/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		njohnston@globaltetrahedron.com
HOMEPAGE=		http://www.diplom.org/Online/mapsoftware.html
COMMENT=		Generate postscript maps from results of play-by-email Diplomacy games

MAKEFILE=		makefile
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/mapit
INSTALLATION_DIRS=	bin libexec

post-patch:
	${SED} "s,@PREFIX@,${PREFIX},g" ${WRKSRC}/dipmap > ${WRKSRC}/dipmap.new
	${MV} ${WRKSRC}/dipmap.new ${WRKSRC}/dipmap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dipmap ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mapit
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mapit
	${INSTALL_PROGRAM} ${WRKSRC}/mapit ${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mapit
	${INSTALL_DATA} ${WRKSRC}/README.maps ${PREFIX}/share/doc/mapit
	${INSTALL_DATA} ${WRKSRC}/*.ps ${PREFIX}/share/mapit
	${INSTALL_DATA} ${WRKSRC}/*.info ${PREFIX}/share/mapit

.include "../../mk/bsd.pkg.mk"
