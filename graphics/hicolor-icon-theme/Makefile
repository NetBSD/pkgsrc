# $NetBSD: Makefile,v 1.13 2006/11/28 22:02:34 drochner Exp $
#

DISTNAME=	hicolor-icon-theme-0.10
CATEGORIES=	graphics
MASTER_SITES=	http://icon-theme.freedesktop.org/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://icon-theme.freedesktop.org/wiki/HicolorTheme
COMMENT=	Standard icon theme called hicolor

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
NO_BUILD=	YES
USE_DIRS+=	xdg-1.1
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake

FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${BUILDLINK_PREFIX.gtk2}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons/hicolor"
INSTALL_TEMPLATES+=	../../graphics/hicolor-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/hicolor-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/hicolor\/icon-theme.cache$$/ { next; }

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
