# $NetBSD: Makefile,v 1.4 2005/11/02 18:44:40 minskim Exp $
#

DISTNAME=		genpasswd-1.5
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Random password generator

NO_CONFIGURE=		yes

INSTALL_TARGET=		install install.man DEST=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILD_TARGET=	gcc
.endif

.include "../../mk/bsd.pkg.mk"
