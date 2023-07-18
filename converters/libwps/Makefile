# $NetBSD: Makefile,v 1.44 2023/07/18 13:01:21 nia Exp $

DISTNAME=	libwps-0.4.12
PKGREVISION=	6
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwps/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libwps.sourceforge.net/
COMMENT=	Library for importing Microsoft Works documents
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++11

CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--disable-werror

PKGCONFIG_OVERRIDE+=	libwps.pc.in

.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
