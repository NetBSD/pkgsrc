# $NetBSD: Makefile,v 1.13 2012/10/23 19:51:39 asau Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-205
PKGREVISION=	1

COMMENT=	X11-based motherboard monitoring utility


BUILD_TARGET=	xmbmon

LDFLAGS+=	-Wl,-R${X11BASE}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
