# $NetBSD: Makefile,v 1.11 2024/10/15 01:13:00 mrg Exp $

DISTNAME=	argp-standalone-1.3
PKGNAME=	argp-1.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~nisse/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libc/manual/html_node/Argp.html
COMMENT=	Argument parsing function from glibc
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
FORCE_C_STD=	gnu99

INSTALLATION_DIRS=	include lib

do-install:
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/libargp.la ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/argp.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
