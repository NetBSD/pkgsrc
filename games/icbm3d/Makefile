# $NetBSD: Makefile,v 1.2 1998/07/25 18:03:38 frueauf Exp $
#

DISTNAME=	icbm3d.0.3
PKGNAME=	icbm3d-0.3
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/icbm3d/

MAINTAINER=	root@garbled.net

WRKSRC=		${WRKDIR}/icbm3d
MAKEFILE=	makefile
USE_X11=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/doc/icbm3d
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/icbm3d

.include "../../mk/bsd.pkg.mk"
