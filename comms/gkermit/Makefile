# $NetBSD: Makefile,v 1.4 2001/02/25 04:17:38 hubertf Exp $
#

DISTNAME=	gkermit
PKGNAME=	gkermit-1.00
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.columbia.edu/kermit/gkermit.html
COMMENT=	minimal implementation of the ``kermit'' protocol (GPL'd)

ALL_TARGET=	posix
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${PREFIX}/bin/gkermit; \
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${PREFIX}/man/man1/gkermit.1; \
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gkermit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gkermit

.include "../../mk/bsd.pkg.mk"
