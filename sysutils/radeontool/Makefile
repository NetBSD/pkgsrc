# $NetBSD: Makefile,v 1.9 2012/10/23 19:51:21 asau Exp $

DISTNAME=	radeontool-1.5
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://fdd.com/software/radeon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fdd.com/software/radeon/
COMMENT=	Toggle backlight and external video output on Radeon cards

BUILD_TARGET=		radeontool
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radeontool ${DESTDIR}${PREFIX}/sbin

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
