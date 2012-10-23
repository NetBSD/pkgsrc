# $NetBSD: Makefile,v 1.12 2012/10/23 17:18:41 asau Exp $
#

DISTNAME=	netname-1.7
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Return the canonical network name of a host

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	svr4
.else
BUILD_TARGET=	netname
.endif
INSTALL_TARGET=	inst-all

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

.include "../../mk/bsd.pkg.mk"
