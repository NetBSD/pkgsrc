# $NetBSD: Makefile,v 1.9 2004/12/03 15:15:10 wiz Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-205

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Motherboard monitoring utility

BUILD_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
