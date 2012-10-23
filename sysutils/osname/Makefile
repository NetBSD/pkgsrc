# $NetBSD: Makefile,v 1.8 2012/10/23 19:51:16 asau Exp $
#

DISTNAME=		osname-1.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		# ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Print canonical name of operating system

NO_CONFIGURE=		yes
BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
