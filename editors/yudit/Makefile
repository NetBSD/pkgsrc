# $NetBSD: Makefile,v 1.5 2002/04/04 20:09:55 jdolecek Exp $
#

DISTNAME=	yudit-2.5
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_BUILDLINK_ONLY=	yes

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

post-configure:
	cd ${WRKSRC}/gui/locale && mv cz cs

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
