# $NetBSD: Makefile,v 1.9 1998/07/15 11:45:54 tv Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:44 max Exp
#

DISTNAME=       libpng-1.0.2
PKGNAME=        png-1.0.2
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/

MAINTAINER=     packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

CONFLICTS=	png-0.96

MAKEFILE=       scripts/makefile.std
MAKE_ENV=	LIBTOOL=${PREFIX}/bin/libtool

.include "../../mk/bsd.pkg.mk"
