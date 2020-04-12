# $NetBSD: Makefile,v 1.56 2020/04/12 08:28:03 adam Exp $

DISTNAME=	libgdata-0.16.1
PKGREVISION=	28
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgdata/0.16/}
EXTRACT_SUFX=	.tar.xz

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

# TODO needs gcr and goa packages
#.include "options.mk"
CONFIGURE_ARGS+=	--disable-gnome

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.19.7
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+=	libsoup>=2.26.0
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/liboauth/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
# only needed for tests, but checked for by configure
BUILDLINK_DEPMETHOD.uhttpmock?=	build
.include "../../www/uhttpmock/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
