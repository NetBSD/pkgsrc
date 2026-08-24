# $NetBSD: Makefile,v 1.98 2026/08/24 08:10:39 adam Exp $

DISTNAME=	libvisio-0.1.9
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/libvisio/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libvisio
COMMENT=	Library and tools for parsing the visio file format
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1 OR gnu-gpl-v2

TOOL_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:build pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE=	libvisio.pc.in

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
