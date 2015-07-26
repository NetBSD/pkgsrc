# $NetBSD: Makefile,v 1.3 2015/07/26 14:59:47 youri Exp $

GHCOMMIT=	a0b2b19231c3383f77f106d9cdacb2d148519cfd
DISTNAME=	${GHCOMMIT}
PKGNAME=	elementary-xfce-icon-theme-0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shimmerproject/elementary-xfce/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/shimmerproject/elementary-xfce
COMMENT=	Elementary icons forked, extended and maintained for Xfce
LICENSE=	gnu-gpl-v2

NO_BUILD=	YES
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/elementary-xfce-${GHCOMMIT}

EVAL_PREFIX+=		PREFIX.gtk2=gtk2+
FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX.gtk2}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons"
INSTALL_TEMPLATES+=	../../graphics/elementary-xfce-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/elementary-xfce-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/elementary-xfce\/icon-theme.cache$$/ { next; }
PRINT_PLIST_AWK+=	/^share\/icons\/elementary-xfce-dark\/icon-theme.cache$$/ { next; }
PRINT_PLIST_AWK+=	/^share\/icons\/elemantary-xfce-darker\/icon-theme.cache$$/ { next; }

INSTALLATION_DIRS+=	share/icons

do-install:
	cd ${WRKSRC} && pax -rw -pe e* ${DESTDIR}${PREFIX}/share/icons/


.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
