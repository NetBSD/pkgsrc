# New ports collection makefile for:    depot
# Version required:     5.14
# Date created:         10 Feb 1998
# Whom:                 tv@netbsd.org
#
# $NetBSD: Makefile,v 1.2 1998/02/15 10:51:56 frueauf Exp $
#

DISTNAME=       depot-5.14
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/depot/alpha/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes

MAN1=depot.1 fsi_generate.1 hintservice.1
MAN5=depot.conf.5 depot.pref.5

do-install:
	@cd ${WRKSRC}/src/cmd && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man1 && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man5 && ${MAKE} DESTDIR=${PREFIX} install

.include <bsd.port.mk>
