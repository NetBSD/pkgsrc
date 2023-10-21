# $NetBSD: Makefile,v 1.18 2023/10/21 17:10:24 gdt Exp $

.include "../../graphics/djvulibre-lib/Makefile.common"
PKGNAME=		${DISTNAME:S/-/-lib-/}
PKGREVISION=		3

MAINTAINER=		pkgsrc-users@NetBSD.org

PKGCONFIG_OVERRIDE+=	libdjvu/ddjvuapi.pc.in
BUILD_DIRS=		libdjvu share
INSTALL_DIRS=		libdjvu share

.include "../../mk/bsd.pkg.mk"
