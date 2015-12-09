# $NetBSD: Makefile,v 1.2 2015/12/09 13:20:59 ryoon Exp $

DISTNAME=	sqliteman-1.2.2
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
