# $NetBSD: Makefile,v 1.14 2005/05/02 11:56:53 drochner Exp $

DISTNAME=		gnome-media-2.10.2
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-media/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of audio/multimedia applications for GNOME2

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gst-plugins-cdparanoia>=0.8.8:../../audio/gst-plugins-cdparanoia
DEPENDS+=		gst-plugins-esound>=0.8.8:../../audio/gst-plugins-esound
DEPENDS+=		gst-plugins-oss>=0.8.8:../../audio/gst-plugins-oss

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV+=		XGETTEXT="${LOCALBASE}/bin/xgettext"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
CONFIGURE_ENV+=		CDROM_HOST="bsd"
.endif

GCONF2_SCHEMAS=		CDDB-Slave2.schemas
GCONF2_SCHEMAS+=	gnome-audio-profiles.schemas
GCONF2_SCHEMAS+=	gnome-cd.schemas
GCONF2_SCHEMAS+=	gnome-sound-recorder.schemas

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
