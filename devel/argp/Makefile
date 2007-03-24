# $NetBSD: Makefile,v 1.1.1.1 2007/03/24 16:57:41 agc Exp $

DISTNAME=	argp-standalone-1.3
PKGNAME=	argp-1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~nisse/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libc/manual/html_node/Argp.html
COMMENT=	Argument parsing function from glibc

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_LIB} ${WRKSRC}/libargp.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/argp.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
