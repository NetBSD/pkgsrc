# $NetBSD: Makefile,v 1.12 2003/07/17 22:53:31 grant Exp $
#

DISTNAME=       depot-5.14
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/depot/alpha/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://andrew2.andrew.cmu.edu/depot/depot.html
COMMENT=	Maps several separate packages into a tree without merging them

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	INSTALL="" CC="${CC}"
MAKE_ENV+=	CC="${CC}"

do-install:
	@cd ${WRKSRC}/src/cmd && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man1 && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man5 && ${MAKE} DESTDIR=${PREFIX} install

.include "../../mk/bsd.pkg.mk"
