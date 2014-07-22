# $NetBSD: Makefile,v 1.24 2014/07/22 11:20:33 wiz Exp $

DISTNAME=	libvisio-0.1.0
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/libvisio/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libvisio
COMMENT=	Library and tools for parsing the visio file format
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1 OR gnu-gpl-v2

BUILD_DEPENDS+=	doxygen>=1.8.7:../../devel/doxygen
BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
PKGCONFIG_OVERRIDE=	libvisio.pc.in
USE_TOOLS+=	perl:build

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
