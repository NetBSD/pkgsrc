# $NetBSD: Makefile,v 1.1.1.1 2002/04/09 13:17:24 wiz Exp $

DISTNAME=	mozilla-fonts-1.0
CATEGORIES=	fonts www
MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.myrddin.demon.co.uk/dist/
COMMENT=	optimized fonts for Netscape/Mozilla

USE_X11BASE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mozilla-fonts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mozilla-fonts

.include "../../mk/bsd.pkg.mk"
