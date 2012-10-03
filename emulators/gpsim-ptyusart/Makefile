# $NetBSD: Makefile,v 1.24 2012/10/03 12:55:14 asau Exp $
#

DISTNAME=	ptyusart-0.3.2
PKGNAME=	gpsim-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Pseudo-tty module for gpsim

ONLY_FOR_PLATFORM=	NetBSD-*-*

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config

GCC_REQD+=		3.0

EGDIR=		${PREFIX}/share/examples/gpsim-ptyusart
INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txdot.asm ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txrx.asm ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txrx.stc ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tstloopback.c ${DESTDIR}${EGDIR}

.include "../../emulators/gpsim-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
