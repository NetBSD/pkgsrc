# $NetBSD: Makefile,v 1.58 2025/10/23 20:36:49 wiz Exp $
#

DISTNAME=	oscilloscope-0.1.2
PKGNAME=	gpsim-${DISTNAME}
PKGREVISION=	48
CATEGORIES=	emulators
MASTER_SITES=	https://largo.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Oscilloscope module for gpsim

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	YES

EGDIR=		${PREFIX}/share/examples/gpsim-oscilloscope

INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txdot.asm ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txdot.stc ${DESTDIR}${EGDIR}

.include "../../emulators/gpsim-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
