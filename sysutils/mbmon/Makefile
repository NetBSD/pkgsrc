# $NetBSD: Makefile,v 1.7 2004/07/19 10:10:10 recht Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-204

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
