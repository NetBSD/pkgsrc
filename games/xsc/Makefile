# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:25 joerg Exp $
#

DISTNAME=		xsc-1.5
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.panix.com/~mbh/xsc/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.panix.com/~mbh/xsc/
COMMENT=		Star Castle clone

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++
INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsc ${PREFIX}/bin/xsc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xsc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xsc

.include "../../mk/bsd.pkg.mk"
