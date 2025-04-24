# $NetBSD: Makefile,v 1.20 2025/04/24 14:14:15 wiz Exp $

PKGREVISION= 1
.include "../../graphics/djvulibre-lib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-lib-/}

MAINTAINER=	pkgsrc-users@NetBSD.org

PKGCONFIG_OVERRIDE+=	libdjvu/ddjvuapi.pc.in
BUILD_DIRS=		libdjvu share
INSTALL_DIRS=		libdjvu share

.include "../../mk/bsd.pkg.mk"
