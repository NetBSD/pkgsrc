# $NetBSD: Makefile,v 1.6 2004/04/07 13:59:40 recht Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-203
PKGREVISION=	1

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
