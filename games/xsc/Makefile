# $NetBSD: Makefile,v 1.3 2005/06/01 18:02:53 jlam Exp $
#

DISTNAME=		xsc-1.5
CATEGORIES=		games
MASTER_SITES=		http://www.panix.com/~mbh/xsc/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.panix.com/~mbh/xsc/
COMMENT=		Star Castle clone

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsc ${PREFIX}/bin/xsc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xsc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xsc

.include "../../mk/bsd.pkg.mk"
