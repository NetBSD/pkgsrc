# $NetBSD: Makefile,v 1.30 2005/05/22 03:04:29 jlam Exp $

DISTNAME=	dx-4.3.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.opendx.org/
COMMENT=	Open Visualization Data Explorer

USE_X11BASE=		yes
USE_GNU_TOOLS+=		make
USE_TOOLS+=		lex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-javadx

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

# Override ARCH to avoid picking up a bad ${ARCH} during the build.
MAKE_ENV+=		ARCH=""
CONFIGURE_ENV+=		ARCH=""

.include "../../devel/hdf/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
