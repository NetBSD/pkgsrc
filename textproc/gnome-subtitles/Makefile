# $NetBSD: Makefile,v 1.12 2011/01/13 13:39:27 wiz Exp $

DISTNAME=	gnome-subtitles-0.9.1
PKGREVISION=	4
CATEGORIES=	multimedia textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnome-subtitles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnome-subtitles.sourceforge.net/
COMMENT=	Subtitle editor for the GNOME desktop
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share
USE_TOOLS+=		bash:run gmake msgfmt perl pkg-config intltool

REPLACE_BASH=		src/GnomeSubtitles/Execution/gnome-subtitles.in
GCONF_SCHEMAS+=		gnome-subtitles.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.3
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
