# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:44 jlam Exp $
#

DISTNAME=		xsc-1.5
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.panix.com/~mbh/xsc/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
