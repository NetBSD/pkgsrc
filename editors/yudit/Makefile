# $NetBSD: Makefile,v 1.6 2002/10/10 00:05:41 wiz Exp $
#

DISTNAME=	yudit-2.5
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

post-configure:
	cd ${WRKSRC}/gui/locale && mv cz cs

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
