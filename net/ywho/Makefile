# $NetBSD: Makefile,v 1.6 2004/07/24 23:56:29 grant Exp $
#

DISTNAME=		ywho-1.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Who, users, uptime on clients in a sun-RPC network

USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes
ALL_TARGET=		all DEST=${PREFIX}
INSTALL_TARGET=		install install.man DEST=${PREFIX}

.include "../../mk/bsd.pkg.mk"
