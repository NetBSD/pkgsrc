# $NetBSD: Makefile,v 1.12 2019/11/02 22:24:42 rillig Exp $

DISTNAME=	mozilla-fonts-1.0
PKGREVISION=	4
CATEGORIES=	fonts www
#MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://www.myrddin.demon.co.uk/dist/
COMMENT=	Optimized fonts for Netscape/Mozilla

USE_TOOLS+=		bdftopcf gzip
FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/Mozilla
REQD_DIRS+=		${PREFIX}/share/fonts/X11/Mozilla

INSTALLATION_DIRS=	share/doc/mozilla-fonts

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mozilla-fonts

.include "../../mk/bsd.pkg.mk"
