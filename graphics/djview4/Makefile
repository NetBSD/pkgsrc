# $NetBSD: Makefile,v 1.4 2009/08/26 19:57:38 sno Exp $
#

DISTNAME=	djview4-4.2-2
PKGNAME=	djview4-4.2.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://djvu.sourceforge.net/
COMMENT=	Portable DjVu viewer and browser plugin

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/djview4-4.2
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
