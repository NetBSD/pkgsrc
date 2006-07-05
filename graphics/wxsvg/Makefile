# $NetBSD: Makefile,v 1.5 2006/07/05 19:47:17 wiz Exp $
#

DISTNAME=	wxsvg-1.0b6
PKGNAME=	${DISTNAME:S/b/beta/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxsvg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wxsvg.sourceforge.net/
COMMENT=	C++ library to create, manipulate and render SVG files

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
