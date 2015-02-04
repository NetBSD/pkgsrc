# $NetBSD: Makefile,v 1.1 2015/02/04 17:31:40 ryoon Exp $

DISTNAME=	libpagemaker-0.0.2
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/libpagemaker/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libpagemaker
COMMENT=	Library and utilities for Adobe PageMaker files
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libpagemaker.pc.in
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
