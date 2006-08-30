# $NetBSD: Makefile,v 1.1.1.1 2006/08/30 17:09:39 drochner Exp $
#

DISTNAME=		djvulibre-3.5.17
PKGNAME=		djvulibre-tools-3.5.17
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://djvulibre.djvuzone.org/
COMMENT=		Compression library for scanned documents

PATCHDIR=		${.CURDIR}/../djvulibre-lib/patches
DISTINFO_FILE=		${.CURDIR}/../djvulibre-lib/distinfo

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

MAKE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
BUILD_DIRS=		tools xmltools
INSTALL_DIRS=		tools xmltools

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
