# $NetBSD: Makefile,v 1.13 2024/05/16 23:36:00 gutteridge Exp $

DISTNAME=	elementary-xfce-icon-theme-0.19
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shimmerproject/}
GITHUB_PROJECT=	elementary-xfce
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/shimmerproject/elementary-xfce
COMMENT=	Elementary icons forked, extended and maintained for Xfce
LICENSE=	gnu-gpl-v2

NO_BUILD=	YES
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	pax

FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons"
INSTALL_TEMPLATES+=	../../graphics/elementary-xfce-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/elementary-xfce-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/elementary-xfce\/icon-theme.cache$$/ { next; }
PRINT_PLIST_AWK+=	/^share\/icons\/elementary-xfce-dark\/icon-theme.cache$$/ { next; }
PRINT_PLIST_AWK+=	/^share\/icons\/elemantary-xfce-darker\/icon-theme.cache$$/ { next; }

INSTALLATION_DIRS+=	share/icons

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm e* AUTHORS CONTRIBUTORS LICENSE README.md \
	${DESTDIR}${PREFIX}/share/icons/

.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
