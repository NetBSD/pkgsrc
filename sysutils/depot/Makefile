# $NetBSD: Makefile,v 1.16 2006/06/20 22:22:23 minskim Exp $
#

DISTNAME=       depot-5.14
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/depot/alpha/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://asg.web.cmu.edu/depot/
COMMENT=	Maps several separate packages into a tree without merging them

GNU_CONFIGURE=	yes
USE_TOOLS+=	yacc

CONFIGURE_ENV+=	INSTALL="" CC=${CC:Q}
MAKE_ENV+=	CC=${CC:Q}

do-install:
	@cd ${WRKSRC}/src/cmd && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man1 && ${MAKE} DESTDIR=${PREFIX} install
	@cd ${WRKSRC}/man/man5 && ${MAKE} DESTDIR=${PREFIX} install

.include "../../mk/bsd.pkg.mk"
