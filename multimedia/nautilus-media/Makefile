# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:03 tv Exp $
#

DISTNAME=	nautilus-media-0.8.1
PKGREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-media/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://thomas.apestaart.org/projects/nautilus-media/
COMMENT=	Multimedia add-ons for Nautilus

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gst-plugins-esound>=0.8.0:../../audio/gst-plugins-esound
DEPENDS+=		gst-plugins-flac>=0.8.0:../../audio/gst-plugins-flac
DEPENDS+=		gst-plugins-gnomevfs>=0.8.0:../../sysutils/gst-plugins-gnomevfs
DEPENDS+=		gst-plugins-mad>=0.8.0:../../audio/gst-plugins-mad
DEPENDS+=		gst-plugins-png>=0.8.0:../../graphics/gst-plugins-png
DEPENDS+=		gst-plugins-vorbis>=0.8.0:../../audio/gst-plugins-vorbis

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gst-thumbnail.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
