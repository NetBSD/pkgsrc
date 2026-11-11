# $NetBSD: Makefile,v 1.43 2026/11/11 11:52:08 wiz Exp $

DISTNAME=	libqxp-0.0.3
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libqxp
COMMENT=	Library that parses the file format of QuarkXPress documents
LICENSE=	mpl-2.0 OR gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
FORCE_CXX_STD=		c++17
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libqxp-0.0.pc

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
