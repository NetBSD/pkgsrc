# $NetBSD: Makefile,v 1.8 2020/06/16 13:43:36 mef Exp $
#

DISTNAME=	predict-2.2.6
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/kd2bd/

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://www.qsl.net/kd2bd/predict.html
COMMENT=	Curses satellite tracking/orbital prediction program

LICENSE=	gnu-gpl-v2

FAKE_NCURSES=	yes
USE_LANGUAGES=	c

LDFLAGS.SunOS+=	-lsocket -lnsl

do-configure:
	printf "const char predictpath[] = \"${PREFIX}/share/predict/\";\n" > "${WRKSRC}/predict.h"
	printf "const int soundcard = 1;\n" >> "${WRKSRC}/predict.h"
	printf "const char version[] = \"$$(cat "${WRKSRC}/.version")\";\n" >> "${WRKSRC}/predict.h"

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} predict.c -o predict -lm -lncurses -lpthread
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/vocalizer.sh > ${WRKSRC}/vocalizer/vocalizer.sh

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/predict/default share/predict/vocalizer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/vocalizer/vocalizer.sh ${DESTDIR}${PREFIX}/share/predict/vocalizer/vocalizer
	${INSTALL_MAN} ${WRKSRC}/docs/man/predict.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/predict.1
	${INSTALL_DATA} ${WRKSRC}/vocalizer/*.wav ${DESTDIR}${PREFIX}/share/predict/vocalizer/
	${INSTALL_DATA} ${WRKSRC}/default/predict.* ${DESTDIR}${PREFIX}/share/predict/default/

# Run time only dependency on the play utility
DEPENDS+=	sox-[0-9]*:../../audio/sox

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
