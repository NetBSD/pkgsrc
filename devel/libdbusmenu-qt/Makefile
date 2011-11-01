# $NetBSD: Makefile,v 1.3 2011/11/01 06:00:58 sbd Exp $
#

DISTNAME=	libdbusmenu-qt-0.8.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/libdbusmenu-qt/trunk/0.8.2/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.canonical.com/~agateau/dbusmenu/index.html
COMMENT=	dbusmenu library for Qt
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=  c c++
USE_CMAKE=      yes
CMAKE_ARGS+=	-DWITH_DOC=OFF

PKGCONFIG_OVERRIDE+=	dbusmenu-qt.pc.in

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
