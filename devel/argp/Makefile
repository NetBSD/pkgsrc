# $NetBSD: Makefile,v 1.5 2018/09/28 20:07:50 wiedi Exp $

DISTNAME=	argp-standalone-1.3
PKGNAME=	argp-1.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~nisse/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libc/manual/html_node/Argp.html
COMMENT=	Argument parsing function from glibc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99

INSTALLATION_DIRS=	include lib

do-install:
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/libargp.la ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/argp.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
