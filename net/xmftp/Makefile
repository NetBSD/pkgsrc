# $NetBSD: Makefile,v 1.21 2015/07/04 16:18:39 joerg Exp $
#

DISTNAME=	xmftp-1.0.4
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://viraj.org/old/xmftp/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://viraj.org/old/xmftp/
COMMENT=	X/Motif FTP client

WRKSRC=		${WRKDIR}/xmftp/source
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/xmftp

LDFLAGS.SunOS+=	-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmftp ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../BUGS ${DESTDIR}${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../CHANGES ${DESTDIR}${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../FAQ ${DESTDIR}${PREFIX}/share/doc/xmftp

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
