# $NetBSD: Makefile,v 1.8 2005/06/01 18:03:23 jlam Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-205

COMMENT=	X11-based motherboard monitoring utility


BUILD_TARGET=	xmbmon

LDFLAGS+=	-Wl,-R${X11BASE}/lib

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
