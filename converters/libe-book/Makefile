# $NetBSD: Makefile,v 1.36 2019/07/01 04:07:45 ryoon Exp $

DISTNAME=	libe-book-0.1.3
PKGREVISION=	8
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libebook/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/libebook/
COMMENT=	Library for importing non-HTML reflowable e-book formats
LICENSE=	mpl-2.0 OR gnu-lgpl-v2.1

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM+=	rm:-Werror

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libe-book.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/liblangtag/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
