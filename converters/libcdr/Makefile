# $NetBSD: Makefile,v 1.36 2018/08/16 18:54:27 adam Exp $

DISTNAME=	libcdr-0.1.4
PKGREVISION=	6
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/libcdr/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libcdr
COMMENT=	Corel Draw file format importer library
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1 OR gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE=	libcdr.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
