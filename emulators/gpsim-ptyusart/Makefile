# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 20:55:51 bouyer Exp $
#

DISTNAME=	ptyusart-0.3.1
PKGNAME=	gpsim-${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Pseudo-tty module for gpsim

ONLY_FOR_PLATFORM=      NetBSD-*-*

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++

USE_LIBTOOL=	YES

EGDIR=		${PREFIX}/share/examples/gpsim-ptyusart
post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/examples;					\
	${INSTALL_DATA} tst_txdot.asm ${EGDIR};			\
	${INSTALL_DATA} tst_txrx.asm ${EGDIR};			\
	${INSTALL_DATA} tst_txrx.stc ${EGDIR};			\
	${INSTALL_DATA} tstloopback.c ${EGDIR};

.include "../../emulators/gpsim-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
