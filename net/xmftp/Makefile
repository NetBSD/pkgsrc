# $NetBSD: Makefile,v 1.10 2005/05/22 20:08:26 jlam Exp $
#

DISTNAME=	xmftp-1.0.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cse.fau.edu/~valankar/old/xmftp/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.cse.fau.edu/~valankar/old/xmftp/
COMMENT=	X/Motif FTP client

WRKSRC=		${WRKDIR}/xmftp/source
USE_X11BASE=	yes
USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmftp ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../BUGS ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../CHANGES ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../FAQ ${PREFIX}/share/doc/xmftp

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
