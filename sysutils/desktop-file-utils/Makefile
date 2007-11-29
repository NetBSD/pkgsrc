# $NetBSD: Makefile,v 1.21 2007/11/29 22:08:34 heinz Exp $
#

DISTNAME=	desktop-file-utils-0.14
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://freedesktop.org/software/desktop-file-utils/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/desktop-file-utils
COMMENT=	Utilities to manage desktop entries

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	EMACS=no

FILES_SUBST+=		APPLICATIONS_PATH="${PREFIX}/share/applications"
FILES_SUBST+=		UPDATE_DESKTOPDB="${PREFIX}/bin/update-desktop-database"

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ \
				{ print "@comment in INSTALL script: " $$0; \
				  next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
