# $NetBSD: Makefile,v 1.1.1.1 2003/05/28 07:22:54 agc Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-201

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
