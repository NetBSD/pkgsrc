# $NetBSD: Makefile,v 1.3 2003/07/21 16:47:08 martti Exp $

DISTNAME=	mozilla-fonts-1.0
CATEGORIES=	fonts www
MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.myrddin.demon.co.uk/dist/
COMMENT=	Optimized fonts for Netscape/Mozilla

USE_X11BASE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mozilla-fonts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mozilla-fonts

.include "../../mk/bsd.pkg.mk"
