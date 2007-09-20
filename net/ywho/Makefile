# $NetBSD: Makefile,v 1.9 2007/09/20 08:57:53 rillig Exp $
#

DISTNAME=		ywho-1.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Who, users, uptime on clients in a sun-RPC network

NO_CONFIGURE=		yes
MAKE_FLAGS+=		DEST=${PREFIX}
BUILD_TARGET=		all
INSTALL_TARGET=		install install.man

.include "../../mk/bsd.pkg.mk"
