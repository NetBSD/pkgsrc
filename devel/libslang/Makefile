# $NetBSD: Makefile,v 1.9 1998/07/15 14:15:59 tv Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:41 max Exp 
#

DISTNAME=       slang1.2.2
PKGNAME=        libslang-1.2.2
CATEGORIES=	devel
MASTER_SITES=   ftp://space.mit.edu/pub/davis/slang/

MAINTAINER=     packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

GNU_CONFIGURE=  yes
MAKE_ENV=	LIBTOOL=${PREFIX}/bin/libtool
WRKSRC=         ${WRKDIR}/slang

.include "../../mk/bsd.pkg.mk"
