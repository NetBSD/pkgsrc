# New packages collection Makefile for: xxgdb
# Version required:     1.12
# Date created:         17-Feb-98
# Whom:                 rh@trapdoor.vip.at
#
# $NetBSD: Makefile,v 1.1 1998/03/01 21:21:15 tron Exp $
#

DISTNAME=	xxgdb-1.12
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	rh@trapdoor.vip.at

WRKSRC=		$(WRKDIR)/$(DISTNAME)
USE_IMAKE=	yes

MAN1=		xxgdb.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XDbx.ad ${PREFIX}/lib/X11/app-defaults/XDbx
	${INSTALL_DATA} ${WRKSRC}/xxgdb.man ${PREFIX}/man/man1/xxgdb.1

.include <bsd.port.mk>
