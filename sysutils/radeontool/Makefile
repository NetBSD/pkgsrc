# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:34 jlam Exp $

DISTNAME=	radeontool-1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://fdd.com/software/radeon/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://fdd.com/software/radeon/
COMMENT=	Toggle backlight and external video output on Radeon cards

BUILD_TARGET=		radeontool
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radeontool ${PREFIX}/sbin

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
