# $NetBSD: Makefile,v 1.19 2022/01/10 01:46:26 ryoon Exp $

DISTNAME=	libstaroffice-0.0.7
PKGREVISION=	5
CATEGORIES=	converters
MASTER_SITES=	https://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://dev-www.libreoffice.org/src/
COMMENT=	Library to import StarOffice documents
LICENSE=	mpl-2.0 OR gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.7

CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libstaroffice.pc.in

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
