# $NetBSD: Makefile,v 1.3 1998/07/25 18:04:44 frueauf Exp $
#

DISTNAME=	xbomber.0.8
PKGNAME=	xbomber-0.8
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/xbomber/

MAINTAINER=	root@garbled.net

WRKSRC=		${WRKDIR}/xbomber
MAKEFILE=	makefile
USE_X11=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/doc/xbomber
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/xbomber

.include "../../mk/bsd.pkg.mk"
