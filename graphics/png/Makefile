# $NetBSD: Makefile,v 1.7 1998/04/20 11:56:24 frueauf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:44 max Exp
#

DISTNAME=       libpng-0.96
PKGNAME=        png-0.96
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/
EXTRACT_SUFX=   .tgz

MAINTAINER=     packages@netbsd.org

MAKEFILE=       makefile

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
