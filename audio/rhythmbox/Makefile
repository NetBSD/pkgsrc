# $NetBSD: Makefile,v 1.14 2004/04/22 09:06:52 jmmv Exp $
#

DISTNAME=	rhythmbox-0.8.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rhythmbox/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.rhythmbox.org/
COMMENT=	Music management application for GNOME

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gst-plugins-esound>=0.8.0:../../audio/gst-plugins-esound
DEPENDS+=		gst-plugins-gnomevfs>=0.8.0:../../sysutils/gst-plugins-gnomevfs
DEPENDS+=		gst-plugins-mad>=0.8.0:../../audio/gst-plugins-mad
DEPENDS+=		gst-plugins-vorbis>=0.8.0:../../audio/gst-plugins-vorbis

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

PKGCONFIG_OVERRIDE=	data/rhythmbox.pc.in

GCONF2_SCHEMAS=		rhythmbox.schemas

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
