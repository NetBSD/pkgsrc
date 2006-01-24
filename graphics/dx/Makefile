# $NetBSD: Makefile,v 1.36 2006/01/24 07:32:11 wiz Exp $

DISTNAME=	dx-4.3.2
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.opendx.org/
COMMENT=	Open Visualization Data Explorer

USE_X11BASE=		yes
USE_TOOLS+=		gmake lex sh
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-javadx
CONFIGURE_ENV+=		bsh_path=${TOOLS_SH:Q}

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
