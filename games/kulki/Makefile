# $NetBSD: Makefile,v 1.4 2001/06/24 01:30:39 zuntum Exp $
#

DISTNAME=	kulki-1.01
CATEGORIES=	games
MASTER_SITES=	http://www.cs.put.poznan.pl/adanilecki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.cs.put.poznan.pl/adanilecki/
COMMENT=	Simple logic game - "balls"

DEPENDS+=	qt2>=2.2.3:../../x11/qt2

WRKSRC=		${WRKDIR}/kulki

USE_X11=	YES
USE_GMAKE=	YES

MAKE_ENV=	QTDIR="${X11BASE}/qt2" MOC="${QTDIR}/bin/moc" CXX="${CXX}" CP="${CP}"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kulki
	${INSTALL_PROGRAM} ${WRKSRC}/kulki ${PREFIX}/bin
	cd ${WRKSRC} &&						\
	${INSTALL_DATA} BUGS CHANGES FAQ README README.PL TODO	\
		help.html pomoc.html ${PREFIX}/share/kulki
	cd ${PREFIX}/share/kulki &&				\
		( ${GUNZIP_CMD} -c ${WRKSRC}/images.tgz | ${GTAR} xf - )

.include "../../mk/bsd.pkg.mk"
