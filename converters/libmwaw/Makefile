# $NetBSD: Makefile,v 1.24 2020/03/25 10:44:04 nia Exp $

DISTNAME=	libmwaw-0.3.16
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmwaw/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://sourceforge.net/p/libmwaw/wiki/Home/
COMMENT=	Import library for pre-OSX Mac text formats
LICENSE=	mpl-2.0 OR gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.7

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libmwaw.pc.in

.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
