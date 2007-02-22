# $NetBSD: Makefile,v 1.14 2007/02/22 19:26:47 wiz Exp $

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

.include "../../mk/bsd.pkg.mk"
