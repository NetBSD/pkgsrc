# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:34 jlam Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-205
PKGREVISION=	1

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Motherboard monitoring utility

BUILD_TARGET=	mbmon

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mbmon.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
