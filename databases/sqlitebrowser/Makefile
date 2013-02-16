# $NetBSD: Makefile,v 1.10 2013/02/16 11:20:41 wiz Exp $

DISTNAME=	sqlitebrowser-1.3-src
PKGNAME=	sqlitebrowser-1.3
PKGREVISION=	7
CATEGORIES=	databases x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sqlitebrowser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	QT3 lightweight GUI editor/viewer for SQLite Databases
HOMEPAGE=	http://sqlitebrowser.sourceforge.net/

WRKSRC=		${WRKDIR}/sqlitebrowser

USE_LANGUAGES=	c c++
QMAKE=		${QTDIR}/bin/qmake

INSTALLATION_DIRS=	bin

BUILDLINK_DEPMETHOD.qt3-tools=	build

do-configure:
	cd ${WRKSRC} && ${QMAKE} QMAKE=${QMAKE:Q} sqlitedbbrowser.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlitebrowser/sqlitebrowser ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
