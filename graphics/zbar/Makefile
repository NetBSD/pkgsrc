# $NetBSD: Makefile,v 1.37 2023/11/15 20:00:41 wiz Exp $

DISTNAME=	zbar-0.23.90
PKGREVISION=	24
CATEGORIES=	graphics
MASTER_SITES=	https://linuxtv.org/downloads/zbar/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/mchehab/zbar
COMMENT=	Bar code reader
LICENSE=	gnu-lgpl-v2.1

# Needed for generating man pages
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-video
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-qt

PKGCONFIG_OVERRIDE+=	zbar-gtk.pc.in
PKGCONFIG_OVERRIDE+=	zbar.pc.in

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
