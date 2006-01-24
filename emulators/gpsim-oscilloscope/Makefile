# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:06 wiz Exp $
#

DISTNAME=	oscilloscope-0.1.2
PKGNAME=	gpsim-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Oscilloscope module for gpsim

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_LIBTOOL=	YES

GCC_REQD+=		3.0

EGDIR=		${PREFIX}/share/examples/gpsim-oscilloscope
post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/examples;					\
	${INSTALL_DATA} tst_txdot.asm ${EGDIR};			\
	${INSTALL_DATA} tst_txdot.stc ${EGDIR};

.include "../../emulators/gpsim-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
