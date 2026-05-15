# $NetBSD: Makefile,v 1.29 2026/05/15 09:58:43 adam Exp $

DISTNAME=	libpagemaker-0.0.4
PKGREVISION=	18
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/libpagemaker/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libpagemaker
COMMENT=	Library and utilities for Adobe PageMaker files
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libpagemaker.pc.in
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
