# $NetBSD: Makefile,v 1.15 2009/12/12 20:22:01 asau Exp $

DISTNAME=               sc-6.21
PKGREVISION=		2
CATEGORIES=             math
MASTER_SITES=           ftp://gatekeeper.dec.com/pub/misc/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		eric@fox.phoenix.az.us
COMMENT=		Curses-based spreadsheet program

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
USE_TOOLS+=		yacc
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
