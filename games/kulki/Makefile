# $NetBSD: Makefile,v 1.5 2001/06/24 02:11:53 zuntum Exp $
#

DISTNAME=	kulki-1.01
CATEGORIES=	games
MASTER_SITES=	http://www.cs.put.poznan.pl/adanilecki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.cs.put.poznan.pl/adanilecki/
COMMENT=	Simple logic game - "balls"

WRKSRC=		${WRKDIR}/kulki

USE_X11=	YES
USE_GMAKE=	YES

USE_BUILDLINK_ONLY=	YES

MAKE_ENV=	QTDIR="${BUILDLINK_DIR}/qt2" MOC="${QTDIR}/bin/moc" CXX="${CXX}" CP="${CP}" \
		CXXFLAGS="-I${QTDIR}/include"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kulki
	${INSTALL_PROGRAM} ${WRKSRC}/kulki ${PREFIX}/bin
	cd ${WRKSRC} &&						\
	${INSTALL_DATA} BUGS CHANGES FAQ README README.PL TODO	\
		help.html pomoc.html ${PREFIX}/share/kulki
	cd ${PREFIX}/share/kulki &&				\
		( ${GUNZIP_CMD} -c ${WRKSRC}/images.tgz | ${GTAR} xf - )

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
