# $NetBSD: Makefile,v 1.7 2006/09/22 21:53:57 joerg Exp $

DISTNAME=	mozilla-fonts-1.0
PKGREVISION=	3
CATEGORIES=	fonts www
#MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://www.myrddin.demon.co.uk/dist/
COMMENT=	Optimized fonts for Netscape/Mozilla

USE_TOOLS+=	bdftopcf
FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/Mozilla
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/Mozilla

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mozilla-fonts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mozilla-fonts

.include "../../mk/bsd.pkg.mk"
