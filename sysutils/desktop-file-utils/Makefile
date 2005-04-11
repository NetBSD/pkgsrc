# $NetBSD: Makefile,v 1.6 2005/04/11 21:47:23 tv Exp $
#

DISTNAME=	desktop-file-utils-0.10
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://freedesktop.org/software/desktop-file-utils/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/desktop-file-utils
COMMENT=	Utilities to manage desktop entries

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	EMACS=no

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

FILES_SUBST+=		APPLICATIONS_PATH="${PREFIX}/share/applications"
FILES_SUBST+=		UPDATE_DESKTOPDB="${PREFIX}/bin/update-desktop-database"

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ \
				{ print "@comment in INSTALL script: " $$0; \
				  next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
