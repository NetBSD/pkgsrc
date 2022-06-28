# $NetBSD: Makefile,v 1.138 2022/06/28 11:33:49 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	19
COMMENT=	XEmacs text editor version 21.4

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
