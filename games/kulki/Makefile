# $NetBSD: Makefile,v 1.16 2004/01/22 07:07:07 grant Exp $
#

DISTNAME=	kulki-1.01
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.cs.put.poznan.pl/adanilecki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.cs.put.poznan.pl/adanilecki/
COMMENT=	Simple logic game - "balls"

WRKSRC=			${WRKDIR}/kulki
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make

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

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
