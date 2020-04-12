# $NetBSD: Makefile,v 1.17 2020/04/12 08:28:03 adam Exp $

DISTNAME=	libgdata-0.6.6
PKGREVISION=	30
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgdata/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://live.gnome.org/libgdata
COMMENT=	Google Data API based Glib client library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	libgdata.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgdata
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.19.7
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+=	libsoup>=2.26.0
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
