# $NetBSD: Makefile,v 1.6 2001/02/25 04:17:49 hubertf Exp $
#

DISTNAME=	icbm3d.0.3
PKGNAME=	icbm3d-0.3
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/icbm3d/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.sonic.net/~nbs/unix/x/icbm3d/
COMMENT=	3D X11 game of defense

WRKSRC=		${WRKDIR}/icbm3d
MAKEFILE=	makefile
USE_X11BASE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icbm3d
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/icbm3d

.include "../../mk/bsd.pkg.mk"
