# $NetBSD: Makefile,v 1.16 2004/10/03 00:13:10 tv Exp $
# FreeBSD: ports/audio/xamp/Makefile,v 1.5 1999/08/25 04:36:22 obrien Exp
#

DISTNAME=	xamp-0.8-10
PKGNAME=	xamp-0.8.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://andrej.co.ru/~andrej/programs/xamp/ \
		http://andrej.co.ru/~andrej/programs/xamp/backs/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SKIN_DATA}

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://andrej.co.ru/~andrej/programs/xamp/
COMMENT=	Version of amp (stands for `Audio Mpeg Player') plus a Qt GUI

WRKSRC=		${WRKDIR}/xamp-0.8/xamp-0.8g
DIST_SUBDIR=	xamp
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS}"
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_X11=	yes

CONFIGURE_ARGS+=	--with-qt-dir=${BUILDLINK_PREFIX.qt1:Q}/qt1

CONFIGURE_ENV+=	QTDIR=${QT1DIR:Q}
MAKE_ENV+=	QT1DIR=${QT1DIR:Q}

SKIN_DATA=	bfamp.tar.gz chrome.tar.gz mmxamp.tar.gz
SKIN_DIR=	${PREFIX}/lib/X11/xamp

post-patch:
	for f in about.cpp aboutData.cpp readmex.h; do \
		${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f.tmp; \
		${SED} -e 's:/usr/X11R6:'${PREFIX}':g' < ${WRKSRC}/$$f.tmp > \
			${WRKSRC}/$$f; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xamp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xamp.1 ${PREFIX}/man/man1
	@${INSTALL_DATA_DIR} ${SKIN_DIR}/bfamp-xamp
	${INSTALL_DATA} ${WRKDIR}/bfamp-xamp/*.bmp ${SKIN_DIR}/bfamp-xamp
	@${INSTALL_DATA_DIR} ${SKIN_DIR}/chrome-xamp
	${INSTALL_DATA} ${WRKDIR}/chrome-xamp/*.bmp ${SKIN_DIR}/chrome-xamp
	@${INSTALL_DATA_DIR} ${SKIN_DIR}/mmxxamp-xamp
	${INSTALL_DATA} ${WRKDIR}/mmxxamp-xamp/*.bmp ${SKIN_DIR}/mmxxamp-xamp

.include "../../x11/qt1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
