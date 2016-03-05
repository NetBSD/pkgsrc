# $NetBSD: Makefile,v 1.3 2016/03/05 11:28:19 jperkin Exp $

DISTNAME=	sqliteman-1.2.2
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sqliteman/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sqliteman.yarpen.cz/
COMMENT=	Sqlite3 developer/admin tool
LICENSE=	gnu-gpl-v2

DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
