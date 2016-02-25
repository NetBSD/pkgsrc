# $NetBSD: Makefile,v 1.16 2016/02/25 16:20:52 jperkin Exp $
#

DISTNAME=	netname-2.2
CATEGORIES=	net
MASTER_SITES=	http://oss.gw.com/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Return the canonical network name of a host

BUILD_TARGET.SunOS=	svr4
BUILD_TARGET.*=		netname

INSTALL_TARGET=	inst-all

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

.include "../../mk/bsd.pkg.mk"
