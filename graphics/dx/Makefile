# $NetBSD: Makefile,v 1.25 2004/04/20 22:11:48 drochner Exp $

DISTNAME=	dx-4.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.opendx.org/
COMMENT=	Open Visualization Data Explorer

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-javadx
CONFIGURE_ENV+=		LEX="flex -l"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

# Override ARCH to avoid picking up a bad ${ARCH} during the build.
MAKE_ENV+=		ARCH=""
CONFIGURE_ENV+=		ARCH=""

.include "../../devel/hdf/buildlink2.mk"
.include "../../devel/netcdf/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
