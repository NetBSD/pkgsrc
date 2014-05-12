# $NetBSD: Makefile,v 1.4 2014/05/12 12:10:11 ryoon Exp $

DISTNAME=	libe-book-0.0.3
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libebook/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libebook/
COMMENT=	Library for importing non-HTML reflowable e-book formats
LICENSE=	mpl-2.0 OR gnu-lgpl-v2.1

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c++

.include "../../mk/bsd.prefs.mk"
# GCC 4.5 or later may be required, and gcc45 is not provided for OpenBSD
.if ${OPSYS} == "OpenBSD"
GCC_REQD+=      4.6
.endif

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libe-book.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
