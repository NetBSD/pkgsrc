# $NetBSD: Makefile,v 1.4 2004/04/07 13:59:40 recht Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-203
PKGREVISION=	1

COMMENT=	X11-based motherboard monitoring utility

USE_X11=	yes

ALL_TARGET=	xmbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
