# $NetBSD: Makefile,v 1.37 2018/04/16 14:34:26 wiz Exp $
#

DISTNAME=	oscilloscope-0.1.2
PKGNAME=	gpsim-${DISTNAME}
PKGREVISION=	29
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Oscilloscope module for gpsim

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	YES

GCC_REQD+=		3.0

EGDIR=		${PREFIX}/share/examples/gpsim-oscilloscope

INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txdot.asm ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/tst_txdot.stc ${DESTDIR}${EGDIR}

.include "../../emulators/gpsim-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
