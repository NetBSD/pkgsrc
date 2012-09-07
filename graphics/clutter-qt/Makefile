# $NetBSD: Makefile,v 1.14 2012/09/07 19:16:42 adam Exp $
#

DISTNAME=	clutter-qt-1.0.0
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-qt/1.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Qt Integratin Library for Clutter
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	clutter-qt.pc.in

CONFIGURE_ARGS+=	--with-moc=${QTDIR}/bin/moc

post-extract:
	rm -f ${WRKSRC}/clutter-qt/moc_clutter-qt.cc
	rm -f ${WRKSRC}/examples/moc_testqt.cc

.include "../../graphics/clutter/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.2.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
