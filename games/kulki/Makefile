# $NetBSD: Makefile,v 1.9 2001/10/23 13:14:53 jlam Exp $
#

DISTNAME=	kulki-1.01
CATEGORIES=	games
MASTER_SITES=	http://www.cs.put.poznan.pl/adanilecki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.cs.put.poznan.pl/adanilecki/
COMMENT=	Simple logic game - "balls"

WRKSRC=		${WRKDIR}/kulki

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

MAKE_ENV+=	CXX="${CXX}"
MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	BASENAME="${BASENAME}"
MAKE_ENV+=	CP="${CP}"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kulki
	${INSTALL_PROGRAM} ${WRKSRC}/kulki ${PREFIX}/bin
	cd ${WRKSRC} &&						\
	${INSTALL_DATA} BUGS CHANGES FAQ README README.PL TODO	\
		help.html pomoc.html ${PREFIX}/share/kulki
	cd ${PREFIX}/share/kulki &&				\
		( ${GUNZIP_CMD} -c ${WRKSRC}/images.tgz | ${GTAR} xf - )

.include "../../mk/x11.buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
