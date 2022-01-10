# $NetBSD: Makefile,v 1.47 2022/01/10 01:46:25 ryoon Exp $

DISTNAME=	libfreehand-0.1.2
PKGREVISION=	12
CATEGORIES=	converters
MASTER_SITES=	https://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://dev-www.libreoffice.org/src/
COMMENT=	Library for Adobe/Macromedia drawings
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:build pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libfreehand.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
