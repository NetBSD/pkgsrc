# $NetBSD: Makefile,v 1.1.1.1 2000/01/04 11:21:57 fredb Exp $
#

DISTNAME=	gkermit
PKGNAME=	gkermit-1.00
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.columbia.edu/kermit/gkermit.html

ALL_TARGET=	posix
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${PREFIX}/bin/gkermit; \
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${PREFIX}/man/man1/gkermit.1; \
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkermit.txt

.include "../../mk/bsd.pkg.mk"
