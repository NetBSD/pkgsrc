# $NetBSD: Makefile,v 1.2 2003/08/23 16:42:00 recht Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-203

COMMENT=	X11-based motherboard monitoring utility

USE_X11=	yes
USE_BUILDLINK2=	yes

ALL_TARGET=	xmbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
