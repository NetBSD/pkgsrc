# $NetBSD: Makefile,v 1.18 2011/12/09 14:36:33 drochner Exp $
#

DISTNAME=	xmftp-1.0.4
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://viraj.org/old/xmftp/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://viraj.org/old/xmftp/
COMMENT=	X/Motif FTP client

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xmftp/source
USE_X11BASE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/xmftp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmftp ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../BUGS ${DESTDIR}${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../CHANGES ${DESTDIR}${PREFIX}/share/doc/xmftp
	${INSTALL_DATA} ${WRKSRC}/../FAQ ${DESTDIR}${PREFIX}/share/doc/xmftp

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
