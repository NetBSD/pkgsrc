# $NetBSD: Makefile,v 1.6 2004/11/22 20:15:29 wiz Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-205

COMMENT=	X11-based motherboard monitoring utility

USE_X11=	yes

ALL_TARGET=	xmbmon

LDFLAGS+=	-Wl,-R${X11BASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
