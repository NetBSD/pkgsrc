# $NetBSD: Makefile,v 1.1.1.1 1999/06/03 16:26:26 tron Exp $
#

DISTNAME=	vipec-1.07
CATEGORIES=	cad
MASTER_SITES=	http://netfold.com/~vipec/public_ftp/unstable/

MAINTAINER=	mcmahill@alum.mit.edu
HOMEPAGE=	http://www.netfold.com/~vipec/

DEPENDS+=	qt-1.42:../../x11/qt

USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vipec ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vipec
	${INSTALL_DATA} ${WRKSRC}/ckt/*.ckt ${PREFIX}/share/examples/vipec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vipec
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/doc/vipec

.include "../../mk/bsd.pkg.mk"
