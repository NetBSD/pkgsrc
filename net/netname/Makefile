# $NetBSD: Makefile,v 1.5 2003/07/21 17:10:52 martti Exp $
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
ALL_TARGET=	netbsd
.endif
INSTALL_TARGET=	inst-all

.include "../../mk/bsd.pkg.mk"
