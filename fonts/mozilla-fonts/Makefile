# $NetBSD: Makefile,v 1.5 2006/02/05 23:09:10 joerg Exp $

DISTNAME=	mozilla-fonts-1.0
PKGREVISION=	1
CATEGORIES=	fonts www
MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.myrddin.demon.co.uk/dist/
COMMENT=	Optimized fonts for Netscape/Mozilla

USE_X11BASE=	yes
USE_TOOLS+=	bdftopcf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mozilla-fonts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mozilla-fonts

.include "../../mk/bsd.pkg.mk"
