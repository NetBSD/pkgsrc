# $NetBSD: Makefile,v 1.61 2026/01/27 08:39:24 wiz Exp $
#

DISTNAME=	ptyusart-0.3.2
PKGNAME=	gpsim-${DISTNAME}
PKGREVISION=	49
CATEGORIES=	emulators
MASTER_SITES=	https://largo.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Pseudo-tty module for gpsim

# Requires openpty() in libutil.
ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-* FreeBSD-*-* DragonFly-*-*

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config

EGDIR=		${PREFIX}/share/examples/gpsim-ptyusart
INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txdot.asm ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txrx.asm ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txrx.stc ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tstloopback.c ${DESTDIR}${EGDIR}

.include "../../emulators/gpsim-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
