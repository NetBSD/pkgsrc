# $NetBSD: Makefile,v 1.1 1998/08/15 13:45:46 frueauf Exp $
#

DISTNAME=		lincity109-src
PKGNAME=		lincity-1.09
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		root@garbled.net

WRKSRC=			${WRKDIR}/lincity109

USE_GMAKE=		yes
USE_X11=		yes
ALL_TARGET=		freebsd

post-patch:
	${TOUCH} ${WRKSRC}/xlincity.man

.include "../../mk/bsd.pkg.mk"
