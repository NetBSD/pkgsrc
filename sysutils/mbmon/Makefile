# $NetBSD: Makefile,v 1.10 2005/01/04 00:33:47 simonb Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-205

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Motherboard monitoring utility

BUILD_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mbmon.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
