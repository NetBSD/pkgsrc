# $NetBSD: Makefile,v 1.4 1999/02/20 22:48:30 hubertf Exp $

DISTNAME=		magicpoint-1.04a
PKGNAME=		mgp-1.04a
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.Mew.org/mgp/

GNU_CONFIGURE=		yes
USE_IMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/README* ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/*.gif ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/*.eps ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/*.mgp ${PREFIX}/share/examples/mgp
	${INSTALL_DATA} ${WRKSRC}/sample/mgprc-sample ${PREFIX}/share/examples/mgp

.include "../../mk/bsd.pkg.mk"
