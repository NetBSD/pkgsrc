# $NetBSD: Makefile,v 1.142 2024/05/29 16:32:51 adam Exp $

DISTNAME=	dx-4.4.4
PKGREVISION=	90
CATEGORIES=	graphics
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opendx.org/
COMMENT=	Open Visualization Data Explorer

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake lex yacc sh
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-javadx
CONFIGURE_ENV+=		bsh_path=${TOOLS_SH}

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

# Override ARCH to avoid picking up a bad ${ARCH} during the build.
MAKE_ENV+=		ARCH=""
CONFIGURE_ENV+=		ARCH=""

.include "../../archivers/libaec/buildlink3.mk"
.include "../../devel/hdf/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
# XXX ImageMagick detection in "configure" is broken
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
