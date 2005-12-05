# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:17 rillig Exp $
#

DISTNAME=	qnetwalk-1.2
PKGREVISION=	1
CATEGORIES=	x11 games
MASTER_SITES=	http://qt.osdn.org.ua/

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://qt.osdn.org.ua/qnetwalk.html
COMMENT=	QNetwalk is a Qt-version of the popular NetWalk game

# We need qmake to build package's Makefile
BUILDLINK_DEPMETHOD.qt3-tools=	build

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

QNETWALK_BIN=	${PREFIX}/bin
QNETWALK_MAN=	${PREFIX}/man/man6
QNETWALK_DATA=	${PREFIX}/share/games/${PKGBASE}
QNETWALK_TR=	${QNETWALK_DATA}
KDEDIR=		${PREFIX:Q}/share/kde

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qnetwalk.pro)

# Fix hardcoded paths
SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	"Fixing hardcoded paths."
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	qnetwalk.pro main.cpp mainwindow.cpp
SUBST_SED.path=		-e 's:@QNETWALK_BIN@:${QNETWALK_BIN}:g'
SUBST_SED.path+=	-e 's:@QNETWALK_MAN@:${QNETWALK_MAN}:g'
SUBST_SED.path+=	-e 's:@QNETWALK_TR@:${QNETWALK_TR}:g'
SUBST_SED.path+=	-e 's:@QNETWALK_DATA@:${QNETWALK_DATA}:g'
SUBST_SED.path+=	-e 's:@KDEDIR@:${KDEDIR}:g'

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
