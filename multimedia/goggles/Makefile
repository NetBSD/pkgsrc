# $NetBSD: Makefile,v 1.5 2010/01/18 09:59:17 wiz Exp $
#

DISTNAME=		goggles-0.9.1
PKGREVISION=		3
CATEGORIES=		multimedia
MASTER_SITES=		http://www.fifthplanet.net/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fifthplanet.net/goggles.html
COMMENT=		Easy to use frontend for Ogle DVD Player

USE_LANGUAGES+=		c c++ # c for configure script
USE_TOOLS+=		gmake bash:run

REPLACE_BASH=		gb

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ./gb --prefix=${PREFIX} \
		--fox-prefix=${BUILDLINK_PREFIX.fox} \
		--ogle-prefix=${BUILDLINK_PREFIX.ogle} \
		--use-config=build/config.generic

do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ./gb --prefix=${PREFIX} install

.include "../../x11/fox/buildlink3.mk"
.include "../../multimedia/ogle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
