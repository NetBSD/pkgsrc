# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:48 agc Exp $
#

DISTNAME=		lincity109-src
PKGNAME=		lincity-1.09
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.floot.demon.co.uk/lincity.html

WRKSRC=			${WRKDIR}/lincity109

USE_GMAKE=		yes
USE_X11BASE=		yes
ALL_TARGET=		freebsd

post-patch:
	${TOUCH} ${WRKSRC}/xlincity.man

.include "../../mk/bsd.pkg.mk"
