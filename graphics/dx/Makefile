# $NetBSD: Makefile,v 1.22 2003/11/30 22:58:41 jschauma Exp $

DISTNAME=	dx-4.2.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Open Visualization Data Explorer

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-javadx
CONFIGURE_ENV+=		LEX="flex -l"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

CPPFLAGS+=		-I${BUILDLINK_PREFIX.freetype-lib}/include/freetype

# Override ARCH to avoid picking up a bad ${ARCH} during the build.
MAKE_ENV+=		ARCH=""
CONFIGURE_ENV+=		ARCH=""

.include "../../devel/netcdf/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
