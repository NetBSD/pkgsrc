# $NetBSD: Makefile,v 1.7 2001/02/16 15:11:01 wiz Exp $
#

DISTNAME=	xbomber.0.8
PKGNAME=	xbomber-0.8
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/xbomber/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/xbomber/
COMMENT=	Colorful game where you blow other people/robots up

WRKSRC=		${WRKDIR}/xbomber
MAKEFILE=	makefile
USE_X11BASE=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/doc/xbomber
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/xbomber

.include "../../mk/bsd.pkg.mk"
