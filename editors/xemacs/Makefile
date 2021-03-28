# $NetBSD: Makefile,v 1.134 2021/03/28 10:36:33 hauke Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	16
COMMENT=	XEmacs text editor version 21.4

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

SUBST_CLASSES+=			desktop-file
SUBST_STAGE.desktop-file=	pre-configure
SUBST_MESSAGE.desktop-file=	Fixing paths in XEmacs desktop file
SUBST_VARS.desktop-file=	PREFIX LIBDIR
SUBST_FILES.desktop-file=	etc/xemacs.desktop

INSTALLATION_DIRS+=		share/applications

.include "Makefile.common"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
