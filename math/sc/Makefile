# $NetBSD: Makefile,v 1.17 2015/03/15 18:51:14 tnn Exp $

DISTNAME=               sc-6.21
PKGREVISION=		2
CATEGORIES=             math
MASTER_SITES=           ftp://gatekeeper.dec.com/pub/misc/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		eric@fox.phoenix.az.us
COMMENT=		Curses-based spreadsheet program

WRKSRC=			${WRKDIR}
USE_TOOLS+=		yacc
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
