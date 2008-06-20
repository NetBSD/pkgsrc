# $NetBSD: Makefile,v 1.16 2008/06/20 01:09:07 joerg Exp $
#

DISTNAME=		sound-juicer-2.14.5
PKGREVISION=		8
CATEGORIES=		audio
MASTER_SITES=		http://www.burtonini.com/computing/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.burtonini.com/computing/
COMMENT=		CD ripping tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt
USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
CONFIGURE_ENV+=		GST_INSPECT="${LOCALBASE}/bin/gst-inspect-0.10"

GCONF_SCHEMAS+=	sound-juicer.schemas

BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.3

.include "../../devel/GConf/schemas.mk"
.include "../../sysutils/nautilus-cd-burner/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gnome-media/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
