# $NetBSD: Makefile,v 1.12 2010/01/27 20:57:22 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

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
