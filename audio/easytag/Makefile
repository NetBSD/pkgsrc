# $NetBSD: Makefile,v 1.90 2014/02/20 07:56:02 wiz Exp $

DISTNAME=	easytag-2.1.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/easytag/2.1/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/easytag/
COMMENT=	GTK+ tag editor for MP3, Ogg Vorbis files, and others
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool pkg-config xgettext

.include "options.mk"

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
