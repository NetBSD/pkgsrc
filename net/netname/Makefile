# $NetBSD: Makefile,v 1.9 2010/02/11 22:18:35 joerg Exp $
#

DISTNAME=	netname-1.7
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Return the canonical network name of a host

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	svr4
.else
BUILD_TARGET=	netname
.endif
INSTALL_TARGET=	inst-all

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
