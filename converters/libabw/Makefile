# $NetBSD: Makefile,v 1.61 2026/08/24 08:24:15 adam Exp $

DISTNAME=	libabw-0.1.4
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://dev-www.libreoffice.org/src/
COMMENT=	Library for AbiWord documents
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:build pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libabw.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
