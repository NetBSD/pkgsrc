# $NetBSD: Makefile,v 1.1.1.1 2002/06/15 09:31:38 shell Exp $

DISTNAME=	Chinput-3.0
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.linuxbyte.net/Chinese/Input/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	Chinese input server

DEPENDS+=	unicon-im>=1.2:../../inputmethod/unicon-im

USE_PTHREAD=	native pth
USE_X11BASE=	yes

ALL_TARGET=	chinput

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

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
