# $NetBSD: Makefile,v 1.5 2003/08/23 16:41:58 recht Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-203

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
