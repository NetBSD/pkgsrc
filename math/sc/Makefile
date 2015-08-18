# $NetBSD: Makefile,v 1.18 2015/08/18 07:31:12 wiz Exp $

DISTNAME=               sc-6.21
PKGREVISION=		3
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
