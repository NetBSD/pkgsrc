# $NetBSD: Makefile,v 1.10 2010/02/11 23:25:51 joerg Exp $
#

DISTNAME=		ywho-1.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Who, users, uptime on clients in a sun-RPC network

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
MAKE_FLAGS+=		DEST=${DESTDIR}${PREFIX}
BUILD_TARGET=		all

INSTALL_TARGET=		install install.man
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
