# $NetBSD: Makefile,v 1.4 2009/06/04 17:29:41 drochner Exp $
#

DISTNAME=		gramps-3.1.1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://gramps-project.org/
COMMENT=		Genealogical Research and Analysis Management Programming System V3

PKG_DESTDIR_SUPPORT=	user-destdir

# not clear, leave off for now
MAKE_JOBS_SAFE=		no

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		msgfmt pkg-config intltool msgconv
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# XXX Why?
CONFIGURE_ARGS+=	--disable-mime-install
# XXX Why?
CONFIGURE_ARGS+=	--enable-packager-mode

# XXX Needed still?
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYTHON_VERSIONS_ACCEPTED=	25 24

## Dependencies are confusing:
# From README
# required:
#   Python 2.5 or greater (works with 2.4 after minor modifications)
#   PyGTK2 2.10 or greater
#   Python Glade bindings (bogus; included in pygtk2)
#   librsvg2 (svg icon view)
# recommended:
#   graphviz
#   xdg (above via USE_DIRS??)
# optional (skipping for now)
#   gtkspell
#   ttf-freefont
# From other sources
# required:
#   gnome-doc-utils (build fails without)
#   py-bsddb3 (and patch)
# recommended/optional:
#   py-gnome (for gnome integration)
#   py25-reportlab (gramps2 MESSAGE, probably no longer)

# See http://gramps-project.org/wiki/index.php?title=Install_latest_BSDDB
.include "../../databases/py-bsddb3/buildlink3.mk"
# XXX Should be option or perhaps not at all
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
# XXX Why, if we disable mime install?
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
