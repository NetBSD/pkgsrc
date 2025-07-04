# $NetBSD: Makefile,v 1.21 2025/07/04 06:25:30 wiz Exp $

.include "../../graphics/djvulibre-lib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-lib-/}

MAINTAINER=	pkgsrc-users@NetBSD.org

PKGCONFIG_OVERRIDE+=	libdjvu/ddjvuapi.pc.in
BUILD_DIRS=		libdjvu share
INSTALL_DIRS=		libdjvu share

.include "../../mk/bsd.pkg.mk"
