# $NetBSD: Makefile,v 1.125 2025/09/23 16:41:10 hauke Exp $

PKGNAME=	${DISTNAME}
COMMENT=	XEmacs text editor version ${PKGVERSION_NOREV}

.include "Makefile.common"

# extra options for x11 support, not for sharing with xemacs-current-nox11
PKG_SUPPORTED_OPTIONS+=		x11 xft2 xface
PKG_SUGGESTED_OPTIONS+=		x11

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
