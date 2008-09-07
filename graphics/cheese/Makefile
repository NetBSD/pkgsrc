# $NetBSD: Makefile,v 1.1.1.1 2008/09/07 22:43:00 jmcneill Exp $

DISTNAME=	cheese-2.22.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cheese/2.22/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/cheese/
COMMENT=	Use your webcam to take photos and videos

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		pkg-config perl intltool gmake
USE_TOOLS+=		autoconf automake autoreconf
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS+=	cheese.schemas

pre-configure:
	cd ${WRKSRC} && autoreconf -vi # -f breaks it

post-install:
.for schema in ${GCONF_SCHEMAS}
	${INSTALL_DATA} ${WRKSRC}/data/${schema} ${PREFIX}/share/gconf/schemas
.endfor

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
DEPENDS+= gst-plugins0.10-theora>=0.10.1:../../multimedia/gst-plugins0.10-theora
DEPENDS+= gst-plugins0.10-ogg>=0.10.1:../../multimedia/gst-plugins0.10-ogg
DEPENDS+= gst-plugins0.10-vorbis>=0.10.1:../../audio/gst-plugins0.10-vorbis
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
