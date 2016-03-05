# $NetBSD: Makefile,v 1.4 2016/03/05 11:28:52 jperkin Exp $

DISTNAME=	trojita-0.4.1
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=trojita/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trojita.flaska.net/
COMMENT=	Fast Qt IMAP e-mail client
LICENSE=	gnu-gpl-v2

DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.qt4-tools+=	qt4-tools>=4.8.6nb2
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
