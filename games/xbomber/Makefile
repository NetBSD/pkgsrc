# $NetBSD: Makefile,v 1.10 2003/11/18 14:43:08 xtraeme Exp $
#

DISTNAME=	xbomber.0.8
PKGNAME=	xbomber-0.8
PKGREVISION=	1
WRKSRC=		${WRKDIR}/xbomber
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/xbomber/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/xbomber/
COMMENT=	Colorful game where you blow other people/robots up

MAKEFILE=	makefile
USE_X11=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xbomber
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/xbomber

.include "../../mk/bsd.pkg.mk"
