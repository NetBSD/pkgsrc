# $NetBSD: Makefile,v 1.11 2006/07/22 04:46:16 rillig Exp $
#

DISTNAME=	hicolor-icon-theme-0.9
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://icon-theme.freedesktop.org/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://icon-theme.freedesktop.org/wiki/HicolorTheme
COMMENT=	Standard icon theme called hicolor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
