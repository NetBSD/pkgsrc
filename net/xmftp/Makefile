# $NetBSD: Makefile,v 1.2 2002/09/23 23:55:25 jlam Exp $
#

DISTNAME=	xmftp-1.0.4
CATEGORIES=	net
MASTER_SITES=	http://www.cse.fau.edu/~valankar/old/xmftp/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.cse.fau.edu/~valankar/old/xmftp/
COMMENT=	X/Motif FTP client

USE_BUILDLINK2=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/xmftp/source

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmftp ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../BUGS ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../CHANGES ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../FAQ ${PREFIX}/share/doc/xmftp

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
