# $NetBSD: Makefile,v 1.3 2004/03/07 01:34:04 snj Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-203

COMMENT=	X11-based motherboard monitoring utility

USE_X11=	yes

ALL_TARGET=	xmbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
