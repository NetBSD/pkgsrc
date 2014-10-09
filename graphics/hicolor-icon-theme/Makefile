# $NetBSD: Makefile,v 1.21 2014/10/09 14:06:35 wiz Exp $

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

EVAL_PREFIX+=		PREFIX.gtk2=gtk2+
FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX.gtk2}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons/hicolor"
INSTALL_TEMPLATES+=	../../graphics/hicolor-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/hicolor-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/hicolor\/icon-theme.cache$$/ { next; }

.include "../../mk/bsd.pkg.mk"
