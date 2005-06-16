# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:59 jlam Exp $

DISTNAME=	Chinput-3.0
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.linuxbyte.net/Chinese/Input/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	Chinese input server

USE_X11BASE=	yes

BUILD_TARGET=	chinput

INSTALLATION_DIRS=	bin etc

post-patch:
	${SED} -e 's:/usr/dict:'${LOCALBASE}/lib/unicon':g' < \
		${WRKSRC}/src/init.c > ${WRKSRC}/src/init.c.tmp
	${SED} -e 's:/usr/lib/ZWinPro:'${PREFIX}/etc':g' < \
		${WRKSRC}/src/init.c.tmp > ${WRKSRC}/src/init.c
	${MV} ${WRKSRC}/resource/Chinput.ad ${WRKSRC}/resource/Chinput.ad.tmp
	${SED} -e 's:/usr/lib/unicon2:'${LOCALBASE}/lib/unicon':g' < \
		${WRKSRC}/resource/Chinput.ad.tmp > \
		${WRKSRC}/resource/Chinput.ad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chinput ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/resource/Chinput.ad ${PREFIX}/etc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Chinput
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/Chinput

.include "../../inputmethod/unicon-im/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
