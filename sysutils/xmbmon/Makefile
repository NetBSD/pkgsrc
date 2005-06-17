# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:36 jlam Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-205

COMMENT=	X11-based motherboard monitoring utility


BUILD_TARGET=	xmbmon

LDFLAGS+=	-Wl,-R${X11BASE}/lib

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
