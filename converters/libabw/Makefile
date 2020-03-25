# $NetBSD: Makefile,v 1.30 2020/03/25 10:56:09 nia Exp $

DISTNAME=	libabw-0.1.3
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://dev-www.libreoffice.org/src/
COMMENT=	Library for AbiWord documents
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:build pkg-config
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.7

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libabw.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
