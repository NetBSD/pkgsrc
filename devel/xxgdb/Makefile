# $NetBSD: Makefile,v 1.5 1999/04/15 20:39:41 tron Exp $
#

DISTNAME=	xxgdb-1.12
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	rh@trapdoor.vip.at

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_IMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDbx.ad ${PREFIX}/lib/X11/app-defaults/XDbx
	${INSTALL_DATA} ${WRKSRC}/xxgdb.man ${PREFIX}/man/man1/xxgdb.1

.include "../../mk/bsd.pkg.mk"
