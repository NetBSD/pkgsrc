# $NetBSD: Makefile,v 1.4 1999/04/15 20:39:42 tron Exp $
#

DISTNAME=		lincity109-src
PKGNAME=		lincity-1.09
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/strategy/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.floot.demon.co.uk/lincity.html

WRKSRC=			${WRKDIR}/lincity109

USE_GMAKE=		yes
USE_X11BASE=		yes
ALL_TARGET=		freebsd

post-patch:
	${TOUCH} ${WRKSRC}/xlincity.man

.include "../../mk/bsd.pkg.mk"
