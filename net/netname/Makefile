# $NetBSD: Makefile,v 1.6 2004/11/25 05:01:21 kim Exp $
#

DISTNAME=	netname-1.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Return the canonical network name of a host

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=	svr4
.else
ALL_TARGET=	netname
.endif
INSTALL_TARGET=	inst-all

.include "../../mk/bsd.pkg.mk"
