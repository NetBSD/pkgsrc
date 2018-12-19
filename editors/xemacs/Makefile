# $NetBSD: Makefile,v 1.122 2018/12/19 13:29:34 hauke Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	4
COMMENT=	XEmacs text editor version 21.4

# extra options for x11 support, not for sharing with xemacs-current-nox11
# Version information in ../../editors/xemacs/Makefile.common

PKG_SUPPORTED_OPTIONS+=		x11 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
