# $NetBSD: Makefile,v 1.30 2006/01/20 16:15:52 jmmv Exp $
#

DISTNAME=	rhythmbox-0.8.8
PKGREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rhythmbox/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rhythmbox.org/
COMMENT=	Music management application for GNOME

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gst-plugins0.8-esound>=0.8.1:../../audio/gst-plugins0.8-esound
DEPENDS+=		gst-plugins0.8-gnomevfs>=0.8.1:../../sysutils/gst-plugins0.8-gnomevfs
DEPENDS+=		gst-plugins0.8-mad>=0.8.1:../../audio/gst-plugins0.8-mad
DEPENDS+=		gst-plugins0.8-vorbis>=0.8.1:../../audio/gst-plugins0.8-vorbis

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

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
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
