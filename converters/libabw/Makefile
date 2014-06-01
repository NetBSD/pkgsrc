# $NetBSD: Makefile,v 1.6 2014/06/01 04:01:06 ryoon Exp $

DISTNAME=	libabw-0.0.2
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://dev-www.libreoffice.org/src/
COMMENT=	Library for AbiWord documents
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:build pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libabw.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
