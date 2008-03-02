# $NetBSD: Makefile,v 1.27 2008/03/02 06:10:34 jlam Exp $

DISTNAME=	xamp-0.8-10
PKGNAME=	xamp-0.8.10
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SKIN_DATA}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	# http://andrej.co.ru/~andrej/programs/xamp/
COMMENT=	Version of amp (stands for `Audio Mpeg Player') plus a Qt GUI

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xamp-0.8/xamp-0.8g
DIST_SUBDIR=	xamp
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS=${CFLAGS:M*:Q}
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-qt-dir=${BUILDLINK_PREFIX.qt1:Q}/qt1

CONFIGURE_ENV+=	QTDIR=${QT1DIR:Q}
MAKE_ENV+=	QT1DIR=${QT1DIR:Q}

SKIN_DATA=	bfamp.tar.gz chrome.tar.gz mmxamp.tar.gz
SKIN_DIR=	${PREFIX}/lib/X11/xamp

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-patch:
	for f in about.cpp aboutData.cpp readmex.h; do \
		${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f.tmp; \
		${SED} -e 's:/usr/X11R6:'${PREFIX}':g' < ${WRKSRC}/$$f.tmp > \
			${WRKSRC}/$$f; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xamp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xamp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	@${INSTALL_DATA_DIR} ${DESTDIR}${SKIN_DIR}/bfamp-xamp
	${INSTALL_DATA} ${WRKDIR}/bfamp-xamp/*.bmp \
		${DESTDIR}${SKIN_DIR}/bfamp-xamp
	@${INSTALL_DATA_DIR} ${DESTDIR}${SKIN_DIR}/chrome-xamp
	${INSTALL_DATA} ${WRKDIR}/chrome-xamp/*.bmp \
		${DESTDIR}${SKIN_DIR}/chrome-xamp
	@${INSTALL_DATA_DIR} ${DESTDIR}${SKIN_DIR}/mmxxamp-xamp
	${INSTALL_DATA} ${WRKDIR}/mmxxamp-xamp/*.bmp \
		${DESTDIR}${SKIN_DIR}/mmxxamp-xamp

.include "../../x11/qt1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
