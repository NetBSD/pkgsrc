# $NetBSD: Makefile,v 1.9 2019/07/01 04:08:00 ryoon Exp $

DISTNAME=	libstaroffice-0.0.2
PKGREVISION=	7
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://dev-www.libreoffice.org/src/
COMMENT=	Library to import StarOffice documents
LICENSE=	mpl-2.0 OR gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libstaroffice.pc.in

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
