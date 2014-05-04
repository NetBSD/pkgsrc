# $NetBSD: Makefile,v 1.2 2014/05/04 17:03:11 wiz Exp $

DISTNAME=	libetonyek-0.0.4
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/libetonyek/
COMMENT=	Library for Apple Keynote presentations
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-docs
CONFIGURE_ARGS+=	--with-boost-filesystem=boost_filesystem

PKGCONFIG_OVERRIDE+=	libetonyek.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
