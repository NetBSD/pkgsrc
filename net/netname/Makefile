# $NetBSD: Makefile,v 1.4 2001/02/17 18:19:14 wiz Exp $
#

DISTNAME=	netname-1.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	return the canonical network name of a host

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=	svr4
.else
ALL_TARGET=	netbsd
.endif
INSTALL_TARGET=	inst-all

.include "../../mk/bsd.pkg.mk"
