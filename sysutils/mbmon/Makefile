# $NetBSD: Makefile,v 1.2 2003/06/02 01:16:54 jschauma Exp $
#

.include "../../sysutils/mbmon/Makefile.common"

PKGNAME=	mbmon-201

MAINTAINER=	tech-pkg@netbsd.org
#HOMEPAGE=	
COMMENT=	motherboard monitoring utility

ALL_TARGET=	mbmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbmon ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
