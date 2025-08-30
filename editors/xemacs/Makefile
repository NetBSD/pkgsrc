# $NetBSD: Makefile,v 1.143 2025/08/30 22:44:58 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	24
COMMENT=	XEmacs text editor version 21.4

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
