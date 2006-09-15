# $NetBSD: Makefile,v 1.41 2006/09/15 15:23:00 jmmv Exp $

DISTNAME=		gnome-media-2.16.1
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-media/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of audio/multimedia applications for GNOME2

DEPENDS+=		gst-plugins0.10-esound>=0.10.0:../../audio/gst-plugins0.10-esound

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config xgettext

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ENV+=		XGETTEXT=${TOOLS_PATH.xgettext:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
CONFIGURE_ENV+=		CDROM_HOST="bsd"
.endif

GCONF2_SCHEMAS=		CDDB-Slave2.schemas
GCONF2_SCHEMAS+=	gnome-audio-profiles.schemas
GCONF2_SCHEMAS+=	gnome-cd.schemas
GCONF2_SCHEMAS+=	gnome-sound-recorder.schemas
GCONF2_SCHEMAS+=	gnome-volume-control.schemas

BUILDLINK_API_DEPENDS.esound+=			esound>=0.2.23
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.3
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.3
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.libgnome+=		libgnomeui>=2.13.7
BUILDLINK_API_DEPENDS.libgnomeui+=		libgnomeui>=2.13.2

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
#.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
