# $NetBSD: Makefile,v 1.17 2023/01/03 17:37:18 wiz Exp $

.include "../../graphics/djvulibre-lib/Makefile.common"
PKGNAME=		${DISTNAME:S/-/-lib-/}
PKGREVISION=		2

MAINTAINER=		pkgsrc-users@NetBSD.org

PKGCONFIG_OVERRIDE+=	libdjvu/ddjvuapi.pc.in
BUILD_DIRS=		libdjvu share
INSTALL_DIRS=		libdjvu share

.include "../../mk/bsd.pkg.mk"
