# $NetBSD: Makefile,v 1.37 2023/12/29 18:24:59 adam Exp $

DISTNAME=	libodfgen-0.1.7
PKGREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/libodfgen/libodfgen-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library to generate ODF documents through libwpd and libwps
LICENSE=	mpl-2.0 OR gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libodfgen.pc.in

.include "../../converters/libetonyek/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
