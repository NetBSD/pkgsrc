# $NetBSD: Makefile,v 1.7 2003/03/29 12:41:05 jmmv Exp $
#

DISTNAME=	icbm3d.0.3
PKGNAME=	icbm3d-0.3
WRKSRC=		${WRKDIR}/icbm3d
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/icbm3d/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.sonic.net/~nbs/unix/x/icbm3d/
COMMENT=	3D X11 game of defense

MAKEFILE=	makefile
USE_X11BASE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icbm3d
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/icbm3d

.include "../../mk/bsd.pkg.mk"
