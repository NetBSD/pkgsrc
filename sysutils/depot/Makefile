# $NetBSD: Makefile,v 1.8 2001/02/17 17:42:12 wiz Exp $
#

DISTNAME=       depot-5.14
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/depot/alpha/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://andrew2.andrew.cmu.edu/depot/depot.html
COMMENT=	Maps several separate packages into a tree without merging them

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	INSTALL="" CC=gcc
MAKE_ENV+=	CC=gcc

do-install:
	@cd ${WRKSRC}/src/cmd && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man1 && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man5 && ${MAKE} DESTDIR=${PREFIX} install

.include "../../mk/bsd.pkg.mk"
