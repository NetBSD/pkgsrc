# $NetBSD: Makefile,v 1.1.1.1 2009/10/27 03:04:22 obache Exp $
#

DISTNAME=	clutter-qt-1.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-qt/1.0/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Qt Integratin Library for Clutter
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	clutter-qt.pc.in

CONFIGURE_ARGS+=	--with-moc=${QTDIR}/bin/moc

.include "../../graphics/clutter/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.2.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
