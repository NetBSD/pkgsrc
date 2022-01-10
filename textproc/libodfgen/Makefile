# $NetBSD: Makefile,v 1.33 2022/01/10 01:46:45 ryoon Exp $

DISTNAME=	libodfgen-0.1.7
PKGREVISION=	5
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
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libodfgen.pc.in

.include "../../converters/libetonyek/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
