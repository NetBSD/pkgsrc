# $NetBSD: Makefile,v 1.1.1.1 2002/04/21 10:47:31 rh Exp $
#

DISTNAME=	xmftp-1.0.4
CATEGORIES=	net
MASTER_SITES=	http://www.cse.fau.edu/~valankar/old/xmftp/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.cse.fau.edu/~valankar/old/xmftp/
COMMENT=	X/Motif FTP client

USE_X11BASE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/xmftp/source

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmftp ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../BUGS ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../CHANGES ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../FAQ ${PREFIX}/share/doc/xmftp

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
