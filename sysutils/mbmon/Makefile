# $NetBSD: Makefile,v 1.8 2004/11/22 20:15:29 wiz Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-205

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
