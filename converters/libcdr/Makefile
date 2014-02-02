# $NetBSD: Makefile,v 1.6 2014/02/02 07:22:15 ryoon Exp $

DISTNAME=	libcdr-0.0.14
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/libcdr/
COMMENT=	Corel Draw file format importer library
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1 OR gnu-gpl-v2

USE_LANGUAGES=	c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE=	libcdr-0.0.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
