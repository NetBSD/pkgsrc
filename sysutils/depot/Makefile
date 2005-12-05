# $NetBSD: Makefile,v 1.14 2005/12/05 20:51:00 rillig Exp $
#

DISTNAME=       depot-5.14
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/depot/alpha/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://asg.web.cmu.edu/depot/
COMMENT=	Maps several separate packages into a tree without merging them

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	INSTALL="" CC=${CC:Q}
MAKE_ENV+=	CC=${CC:Q}

do-install:
	@cd ${WRKSRC}/src/cmd && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man1 && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man5 && ${MAKE} DESTDIR=${PREFIX} install

.include "../../mk/bsd.pkg.mk"
