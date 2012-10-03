# $NetBSD: Makefile,v 1.21.2.1 2012/10/03 12:07:37 spz Exp $
#

DISTNAME=	oscilloscope-0.1.2
PKGNAME=	gpsim-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Oscilloscope module for gpsim

PKG_DESTDIR_SUPPORT=	user-destdir

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
