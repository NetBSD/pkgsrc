# $NetBSD: Makefile,v 1.2 2007/02/05 23:41:49 wiz Exp $
#

DISTNAME=		djvulibre-3.5.18
PKGNAME=		djvulibre-lib-3.5.18
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://djvulibre.djvuzone.org/
COMMENT=		Compression library for scanned documents

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libdjvu/ddjvuapi.pc.in
BUILD_DIRS=		libdjvu
INSTALL_DIRS=		libdjvu

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
