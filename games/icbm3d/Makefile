# $NetBSD: Makefile,v 1.1 1998/07/24 11:41:06 frueauf Exp $
#

DISTNAME=	icbm3d.0.3
PKGNAME=	icbm3d-0.3
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/icbm3d/

MAINTAINER=	root@garbled.net

WRKSRC=		${WRKDIR}/icbm3d

USE_X11=	yes

post-patch:
	@${CP} ${WRKSRC}/makefile ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/share/doc/icbm3d
	${CP} ${WRKSRC}/README.txt ${PREFIX}/share/doc/icbm3d

.include "../../mk/bsd.pkg.mk"
