# $NetBSD: Makefile,v 1.15 2012/09/15 10:06:03 obache Exp $
#

DISTNAME=	libgdata-0.6.6
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgdata/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://live.gnome.org/libgdata
COMMENT=	Google Data API based Glib client library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR= yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool msgfmt
USE_LANGUAGES=	c c++

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
BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.26.0
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
