# $NetBSD: Makefile,v 1.7 2004/12/03 15:15:06 wiz Exp $
#

DISTNAME=	netname-1.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Return the canonical network name of a host

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	svr4
.else
BUILD_TARGET=	netname
.endif
INSTALL_TARGET=	inst-all

.include "../../mk/bsd.pkg.mk"
