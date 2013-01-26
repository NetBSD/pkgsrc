# $NetBSD: Makefile,v 1.16 2013/01/26 21:37:44 adam Exp $

DISTNAME=		djvulibre-3.5.25.3
PKGNAME=		${DISTNAME:S/-/-tools-/}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://djvu.sourceforge.net/
COMMENT=		Compression library for scanned documents
LICENSE=		gnu-gpl-v2

PATCHDIR=		${.CURDIR}/../djvulibre-lib/patches
DISTINFO_FILE=		${.CURDIR}/../djvulibre-lib/distinfo

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run pkg-config
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/djvulibre-3.5.25
MAKE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
BUILD_DIRS=		tools xmltools
INSTALL_DIRS=		tools xmltools

REPLACE_BASH+=		tools/any2djvu

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
