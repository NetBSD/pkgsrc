# $NetBSD: Makefile,v 1.6 2003/12/08 14:41:38 wiz Exp $

DISTNAME=		gnome-media-2.2.1.1
PKGREVISION=		4
CATEGORIES=		audio gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-media/2.2/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of audio/multimedia applications for GNOME2

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_PERL5=		build
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ENV+=		XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS=		CDDB-Slave2.schemas
GCONF2_SCHEMAS+=	gnome-volume-control.schemas
GCONF2_SCHEMAS+=	gnome-sound-recorder.schemas

.include "../../audio/esound/buildlink2.mk"
.include "../../misc/gst-plugins/buildlink2.mk"
.include "../../misc/gstreamer/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink2.mk"
.include "../../devel/gail/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
