# $NetBSD: Makefile,v 1.4 1998/06/21 03:54:34 tv Exp $
#

DISTNAME=       depot-5.14
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/depot/alpha/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	INSTALL=""

MAN1=depot.1 fsi_generate.1 hintservice.1
MAN5=depot.conf.5 depot.pref.5

do-install:
	@cd ${WRKSRC}/src/cmd && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man1 && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man5 && ${MAKE} DESTDIR=${PREFIX} install

.include "../../mk/bsd.pkg.mk"
