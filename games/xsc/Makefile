# $NetBSD: Makefile,v 1.1.1.1 2005/01/03 14:27:07 wiz Exp $
#

DISTNAME=		xsc-1.5
CATEGORIES=		games
MASTER_SITES=		http://www.panix.com/~mbh/xsc/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.panix.com/~mbh/xsc/
COMMENT=		Star Castle clone

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsc ${PREFIX}/bin/xsc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xsc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xsc

.include "../../mk/bsd.pkg.mk"
