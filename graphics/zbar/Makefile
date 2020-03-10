# $NetBSD: Makefile,v 1.5 2020/03/10 22:10:16 wiz Exp $

DISTNAME=	zbar-0.23
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://linuxtv.org/downloads/zbar/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/mchehab/zbar
COMMENT=	Bar code reader
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--disable-video
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-qt

PKGCONFIG_OVERRIDE+=	zbar-gtk.pc.in
PKGCONFIG_OVERRIDE+=	zbar-qt.pc.in
PKGCONFIG_OVERRIDE+=	zbar.pc.in

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
