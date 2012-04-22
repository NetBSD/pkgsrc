# $NetBSD: Makefile,v 1.1.1.1 2012/04/22 17:47:42 wiz Exp $

DISTNAME=	libcdr-0.0.6
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/libcdr/
COMMENT=	Corel Draw file format importer library
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1 OR gnu-gpl-v2

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
PKGCONFIG_OVERRIDE=	libcdr-0.0.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
