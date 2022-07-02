# $NetBSD: Makefile,v 1.25 2022/07/02 16:53:04 ryoon Exp $

DISTNAME=	buzztrax-0.10.2
PKGREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	https://files.buzztrax.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.buzztrax.org/
COMMENT=	Modular, free, open source music studio
LICENSE=	gnu-lgpl-v2.1

# wavenc
TOOL_DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

CONFLICTS+=	buzztard-[0-9]*
SUPERSEDES+=	buzztard-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	intltool perl pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	gmake

PLIST_SRC=	${PLIST_SRC_DFLT}

USE_PKGLOCALEDIR=	yes

CONFIGURE_ENV+=		ac_cv_path_scrollkeeper_config=no
CONFIGURE_ENV+=		ac_cv_path_xvfb_path=no

CONFIGURE_ARGS+=	--disable-dllwrapper

.include "options.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
