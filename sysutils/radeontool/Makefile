# $NetBSD: Makefile,v 1.8 2009/01/12 16:20:54 jmcneill Exp $

DISTNAME=	radeontool-1.5
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://fdd.com/software/radeon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fdd.com/software/radeon/
COMMENT=	Toggle backlight and external video output on Radeon cards

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		radeontool
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radeontool ${DESTDIR}${PREFIX}/sbin

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
