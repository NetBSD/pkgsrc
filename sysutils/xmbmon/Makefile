# $NetBSD: Makefile,v 1.5 2004/07/19 10:10:30 recht Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	xmbmon-204

COMMENT=	X11-based motherboard monitoring utility

USE_X11=	yes

ALL_TARGET=	xmbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
