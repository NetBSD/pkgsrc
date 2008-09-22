# $NetBSD: Makefile,v 1.9 2008/09/22 20:21:03 joerg Exp $
#

DISTNAME=	wxsvg-1.0b6
PKGNAME=	${DISTNAME:S/b/beta/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxsvg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wxsvg.sourceforge.net/
COMMENT=	C++ library to create, manipulate and render SVG files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
