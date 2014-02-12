# $NetBSD: Makefile,v 1.15 2014/02/12 23:17:45 tron Exp $

DISTNAME=	sqlitebrowser_200_b1_src
PKGNAME=	${DISTNAME:S/_200_b1_src/-2.0beta1/1}
PKGREVISION=	4
CATEGORIES=	databases x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sqlitebrowser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Qt4 lightweight GUI editor/viewer for SQLite Databases
HOMEPAGE=	http://sqlitebrowser.sourceforge.net/
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/trunk/sqlitebrowser

USE_LANGUAGES=	c c++
QMAKE=		${QTDIR}/bin/qmake

INSTALLATION_DIRS=	bin

BUILDLINK_DEPMETHOD.qt4-tools=	build

do-configure:
	cd ${WRKSRC} && ${QMAKE} QMAKE=${QMAKE:Q} sqlitedbbrowser.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlitebrowser/sqlitebrowser ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
