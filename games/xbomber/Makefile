# $NetBSD: Makefile,v 1.1 1998/07/24 10:36:09 frueauf Exp $
#

DISTNAME=	xbomber.0.8
PKGNAME=	xbomber-0.8
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/xbomber/

MAINTAINER=	root@garbled.net

WRKSRC=		${WRKDIR}/xbomber

USE_X11=	yes

post-patch:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
