# $NetBSD: Makefile,v 1.22 2015/11/25 12:50:43 jperkin Exp $

DISTNAME=	hicolor-icon-theme-0.13
CATEGORIES=	graphics
MASTER_SITES=	http://icon-theme.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icon-theme.freedesktop.org/wiki/HicolorTheme
COMMENT=	Standard icon theme called hicolor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
NO_BUILD=	YES
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	gmake

FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${LOCALBASE}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons/hicolor"
INSTALL_TEMPLATES+=	../../graphics/hicolor-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/hicolor-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/hicolor\/icon-theme.cache$$/ { next; }

.include "../../mk/bsd.pkg.mk"
