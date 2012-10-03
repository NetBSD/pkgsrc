# $NetBSD: Makefile,v 1.10 2012/10/03 18:28:28 asau Exp $

DISTNAME=	mozilla-fonts-1.0
PKGREVISION=	3
CATEGORIES=	fonts www
#MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://www.myrddin.demon.co.uk/dist/
COMMENT=	Optimized fonts for Netscape/Mozilla

USE_TOOLS+=	bdftopcf gzip
FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/Mozilla
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/Mozilla

INSTALLATION_DIRS=	share/doc/mozilla-fonts

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mozilla-fonts

.include "../../mk/bsd.pkg.mk"
