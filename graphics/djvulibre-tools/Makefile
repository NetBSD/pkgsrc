# $NetBSD: Makefile,v 1.7 2009/08/26 19:57:38 sno Exp $

DISTNAME=		djvulibre-3.5.21
PKGNAME=		djvulibre-tools-3.5.21
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://djvulibre.djvuzone.org/
COMMENT=		Compression library for scanned documents

PKG_DESTDIR_SUPPORT=	user-destdir

PATCHDIR=		${.CURDIR}/../djvulibre-lib/patches
DISTINFO_FILE=		${.CURDIR}/../djvulibre-lib/distinfo

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run pkg-config
GNU_CONFIGURE=		yes

MAKE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
BUILD_DIRS=		tools xmltools
INSTALL_DIRS=		tools xmltools

REPLACE_BASH+=		tools/any2djvu

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
