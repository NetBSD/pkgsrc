# $NetBSD: Makefile,v 1.3 2003/07/17 22:53:41 grant Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-201

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
