# $NetBSD: Makefile,v 1.2 1998/08/24 01:00:26 hubertf Exp $

DISTNAME=		mgp-1.03a
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

.include "../../mk/bsd.pkg.mk"
