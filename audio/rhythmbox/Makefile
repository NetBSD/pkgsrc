# $NetBSD: Makefile,v 1.2 2004/01/26 11:54:45 jmmv Exp $
#

DISTNAME=	rhythmbox-0.6.5
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome/sources/rhythmbox/0.6/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.rhythmbox.org/
COMMENT=	Music management application for GNOME

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

GCONF2_SCHEMAS=		rhythmbox.schemas

.include "../../audio/flac/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../multimedia/gstreamer/buildlink2.mk"
.include "../../misc/gst-plugins/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
