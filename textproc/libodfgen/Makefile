# $NetBSD: Makefile,v 1.41 2025/09/27 09:57:37 wiz Exp $

DISTNAME=	libodfgen-0.1.7
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/libodfgen/libodfgen-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
