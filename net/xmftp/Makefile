# $NetBSD: Makefile,v 1.14 2006/02/05 23:10:33 joerg Exp $
#

DISTNAME=	xmftp-1.0.4
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://viraj.org/old/xmftp/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://viraj.org/old/xmftp/
COMMENT=	X/Motif FTP client

WRKSRC=		${WRKDIR}/xmftp/source
USE_X11BASE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmftp ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../BUGS ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../CHANGES ${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../FAQ ${PREFIX}/share/doc/xmftp

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
