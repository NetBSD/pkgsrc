# $NetBSD: Makefile,v 1.38 2024/06/04 05:38:54 ryoon Exp $

DISTNAME=	libzmf-0.0.2
PKGREVISION=	30
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/libzmf/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://dev-www.libreoffice.org/src/libzmf/
COMMENT=	Library to parse Zoner Callisto/Draw documents
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
FORCE_CXX_STD=	c++17

CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libzmf.pc.in

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
