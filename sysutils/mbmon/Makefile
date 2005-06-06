# $NetBSD: Makefile,v 1.12 2005/06/06 16:08:43 wiz Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-205
PKGREVISION=	1

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Motherboard monitoring utility

BUILD_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mbmon.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
