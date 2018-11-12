# $NetBSD: Makefile,v 1.66 2018/11/12 03:52:59 ryoon Exp $

DISTNAME=	gnome-subtitles-1.3
PKGREVISION=	17
CATEGORIES=	multimedia textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnome-subtitles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnome-subtitles.sourceforge.net/
COMMENT=	Subtitle editor for the GNOME desktop
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share
USE_TOOLS+=		bash:run gmake msgfmt pkg-config intltool
USE_LIBTOOL=		yes

REPLACE_BASH=		src/GnomeSubtitles/Execution/gnome-subtitles.in
GCONF_SCHEMAS+=		gnome-subtitles.schemas

DEPENDS+=	enchant>=1.3:../../textproc/enchant
DEPENDS+=	gtkspell>=2.0:../../textproc/gtkspell

.include "../../devel/GConf/schemas.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
# for gconf-sharp
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
