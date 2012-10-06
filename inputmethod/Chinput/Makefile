# $NetBSD: Makefile,v 1.15 2012/10/06 14:25:10 asau Exp $

DISTNAME=	Chinput-3.0
PKGREVISION=	3
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
	${INSTALL_PROGRAM} ${WRKSRC}/src/chinput ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/resource/Chinput.ad ${DESTDIR}${PREFIX}/etc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/Chinput
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/Chinput

.include "../../inputmethod/unicon-im/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
