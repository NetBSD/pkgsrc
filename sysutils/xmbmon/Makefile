# $NetBSD: Makefile,v 1.7 2004/12/03 15:15:10 wiz Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-205

COMMENT=	X11-based motherboard monitoring utility

USE_X11=	yes

BUILD_TARGET=	xmbmon

LDFLAGS+=	-Wl,-R${X11BASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
