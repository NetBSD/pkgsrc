# $NetBSD: Makefile,v 1.4 2003/07/21 17:24:18 martti Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-201

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
