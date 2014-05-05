# $NetBSD: Makefile,v 1.30 2014/05/05 00:47:53 ryoon Exp $
#

DISTNAME=	rftg-0.8.1
PKGREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://warpcore.org/rftg/ \
		http://keldon.net/rftg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://keldon.net/rftg/
COMMENT=	AI opponent(s) for the card game Race for the Galaxy
#LICENSE=	gnu-gpl-v2 AND ??? (but allowed)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

LIBS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS+=	libexec share/doc/rftg

post-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/rftg.sh
	${ECHO} 'cd ${PREFIX}/share/rftg && ${PREFIX}/libexec/rftg' \
		>> ${WRKSRC}/rftg.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/rftg ${DESTDIR}${PREFIX}/libexec/rftg
	${INSTALL_SCRIPT} ${WRKSRC}/rftg.sh ${DESTDIR}${PREFIX}/bin/rftg
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/rftg

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
